//
//  mainwidget.cpp
//  MainWidget
//
//  Created by Roman Podymov on 06/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#include "mainwidget.h"
#include "foreignexchangerateswidget.h"
#include "foreignexchangerateswidgetadditionaldata.h"
#include "videowidget.h"
#include "videowidgetadditionaldata.h"
#include "weatherwidget.h"
#include "weatherwidgetadditionaldata.h"
#include <QTranslator>
#include <QVBoxLayout>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTimer>
#include <QFile>

MainWidget::MainWidget(const QApplication* application, QWidget *parent): TranslatorWidget(parent),
    application(application),
    stateLabel(new QLabel(this)),
    networkAccessManager(new QNetworkAccessManager()),
    widgetState(WidgetState::unknown),
    localConfiguration(MainWidget::readLocalConfigurationJSON()),
    widgetsConfigurationURL(localConfiguration["widgetsConfigurationURL"].toString()),
    weatherAPIkey(localConfiguration["weatherAPIkey"].toString()),
    exchangeAPIkey(localConfiguration["exchangeAPIkey"].toString()),
    maxRequestErrorCount(5),
    requestErrorCount(0) {
    loadTranslations(application, ":/translations/strings");
    QPointer<QVBoxLayout> rootLayout(new QVBoxLayout());
    rootLayout->setAlignment(Qt::AlignLeading | Qt::AlignTop);
    rootLayout->setSpacing(0);
    setLayout(rootLayout);
    setWindowState(Qt::WindowFullScreen);
    QObject::connect(networkAccessManager.get(), &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply) {
        if (reply->error()) {
            requestErrorCount++;
            if (requestErrorCount >= maxRequestErrorCount) {
                switchWidgetState(WidgetState::error);
            } else {
                update(widgetState, true);
            }
            return;
        } else {
            requestErrorCount = 0;
        }

        switchWidgetState(WidgetState::content);
        const auto nextData = parseRensonse(reply->readAll());
        if (nextData != widgetData) {
            widgetData = nextData;
            updateUI(widgetData);
        }
        update(widgetState, true);
        emit newDataReceived();
    });
    update(WidgetState::loading, false);
}

void MainWidget::keyPressEvent(QKeyEvent*) {
    exit(EXIT_SUCCESS);
}

void MainWidget::resizeEvent(QResizeEvent *event) {
    const auto& size = event->size();
    emit rootScreenSizeChanged(size);
}

void MainWidget::switchWidgetState(WidgetState widgetState) {
    if (this->widgetState == widgetState) {
        return;
    }
    this->widgetState = widgetState;
    switch (widgetState) {
        case WidgetState::unknown:
            stateLabel->hide();
            break;

        case WidgetState::loading: {
            stateLabel->show();
            stateLabel->setText(MainWidget::tr("Loading"));
            break;
        }

        case WidgetState::content:
            stateLabel->hide();
            break;

        case WidgetState::error: {
            stateLabel->show();
            stateLabel->setText(MainWidget::tr("Error"));
            break;
        }
    }
}

QJsonObject MainWidget::readLocalConfigurationJSON() {
    QFile localConfigurationFile(":/configurations/local.json");
    localConfigurationFile.open(QIODevice::ReadOnly);

    const auto& localConfigurationFileContent = QString::fromUtf8(localConfigurationFile.readAll()).simplified();
    const auto& localConfigurationFileJSON = QJsonDocument::fromJson(localConfigurationFileContent.toUtf8());
    localConfigurationFile.close();
    return localConfigurationFileJSON.object();
}

void MainWidget::update(WidgetState nextState, bool withDelay) {
    switchWidgetState(nextState);
    if (withDelay) {
        QTimer::singleShot(widgetData.updateIntervalInSeconds * 1000, this, [=]{
            update();
        });
    } else {
        update();
    }
}

void MainWidget::update() {
    networkAccessManager->get(QNetworkRequest(QUrl(widgetsConfigurationURL)));
}

WidgetData MainWidget::parseRensonse(QString response) {
    const auto& jsonResponse = QJsonDocument::fromJson(response.toUtf8());
    const auto& jsonObject = jsonResponse.object();
    const auto& rows = jsonObject["rows"].toArray();
    WidgetData result;
    result.updateIntervalInSeconds = jsonObject["updateIntervalInSeconds"].toInt();
    for (const QJsonValue& row: rows) {
        WidgetData::WidgetData::Row rowData(row["height"].toString());
        const auto& items = row["items"].toArray();
        for (const QJsonValue& item: items) {
            const auto& widgetType = item["type"].toString();
            const auto& widgetWidth = item["width"].toString();
            const auto& widgetBackgroundImage = item["backgroundImage"].toString();
            const auto& widgetTextColor = item["textColor"].toString();
            auto itemData = WidgetData::WidgetData::Row::Item(
                widgetType, widgetWidth, widgetBackgroundImage, widgetTextColor
            );
            switch (itemData.widgetType) {
            case WidgetData::WidgetType::foreignexchangerates: {
                itemData.additionalWidgetData = QSharedPointer<AdditionalWidgetData>(
                    new ForeignExchangeRatesWidgetAdditionalData(exchangeAPIkey, item["baseCurrency"].toString(), item["targetCurrency"].toString())
                );
                break;
            }
            case WidgetData::WidgetType::player: {
                itemData.additionalWidgetData = QSharedPointer<VideoWidgetAdditionalData>(
                    new VideoWidgetAdditionalData(item["videoURL"].toString())
                );
                break;
            }
            case WidgetData::WidgetType::weather: {
                itemData.additionalWidgetData = QSharedPointer<AdditionalWidgetData>(
                    new WeatherWidgetAdditionalData(weatherAPIkey, item["location"].toString())
                );
                break;
            }
            case WidgetData::WidgetType::unknown:
                break;
            }
            rowData.items.append(itemData);
        }
        result.rows.append(rowData);
    }
    return result;
}

void MainWidget::updateUI(WidgetData widgetData) {
    const auto& rootLayout = qobject_cast<QBoxLayout*>(layout());
    MainWidget::clearLayout(rootLayout);
    foreach (const auto& row, widgetData.rows) {
        QPointer<QHBoxLayout> itemsLayout(new QHBoxLayout());
        itemsLayout->setSpacing(0);
        itemsLayout->setAlignment(Qt::AlignLeading | Qt::AlignTop);
        foreach (const auto& item, row.items) {
            QPointer<BaseWidget> rowWidget = MainWidget::createRowWidget(application, row, item);
            if (rowWidget != nullptr) {
                QObject::connect(this, SIGNAL(rootScreenSizeChanged(QSize)), rowWidget, SLOT(onRootScreenSizeChanged(QSize)));
                rowWidget->setupSize(frameSize());
                application->installTranslator(&rowWidget->translator);
                itemsLayout->addWidget(rowWidget);
            }
        }
        itemsLayout->addSpacerItem(new QSpacerItem(std::numeric_limits<uint>::max(), 0, QSizePolicy::Minimum, QSizePolicy::Minimum));
        rootLayout->addLayout(itemsLayout);
    }
    rootLayout->addSpacerItem(new QSpacerItem(0, std::numeric_limits<uint>::max(), QSizePolicy::Minimum, QSizePolicy::Minimum));
}

QPointer<BaseWidget> MainWidget::createRowWidget(const QApplication* application, const WidgetData::Row& row, const WidgetData::Row::Item& item) {
    CreateWidgetFunction createWidgetFunction;
    switch (item.widgetType) {
        case WidgetData::WidgetType::foreignexchangerates: {
            createWidgetFunction = &ForeignExchangeRatesWidget::create;
            break;
        }
        case WidgetData::WidgetType::player: {
            createWidgetFunction = &VideoWidget::create;
            break;
        }
        case WidgetData::WidgetType::weather: {
            createWidgetFunction = &WeatherWidget::create;
            break;
        }
        case WidgetData::WidgetType::unknown:
            return nullptr;
    }
    std::tuple<const QApplication*, const WidgetData::Row&, const WidgetData::Row::Item&, QWidget*> args(application, row, item, nullptr);
    return std::apply(createWidgetFunction, args);
}

void MainWidget::clearLayout(QLayout* layout) {
    while (!layout->isEmpty()) {
        auto child = layout->takeAt(0);
        auto childLayout = child->layout();
        if (childLayout != nullptr) {
            clearLayout(childLayout);
        } else {
            auto childWidget = child->widget();
            if (childWidget != nullptr) {
                delete childWidget;
            }
        }
        delete child;
    }
}
