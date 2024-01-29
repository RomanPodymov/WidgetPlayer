# WidgetPlayer

![WidgetPlayer running](https://github.com/RomanPodymov/WidgetPlayer/blob/main/Screenshot/running.png "WidgetPlayer running")
 
## Dependencies

* C++17 compatible compiler
* Qt 6.6.1: https://www.qt.io

Before building the app, run `lupdate` and `lrelease`

## ```local_configuration.json```

Set the following values in ```local_configuration.json```
1) **widgetsConfigurationURL**: URL for the widgets configuration. See response example below.
2) **weatherAPIkey**: Token for ```api.openweathermap.org```.
3) **exchangeAPIkey**: Token for ```api.apilayer.com```.


## ```widgetsConfigurationURL``` response example

```
{
  "updateIntervalInSeconds":10,
  "rows": [
  {
    "height":"300", 
    "items": [
      {
       "type":"player", 
       "width":"400", 
       "videoURL":"https://demo.unified-streaming.com/k8s/features/stable/video/tears-of-steel/tears-of-steel.ism/.m3u8",
       "backgroundImage": "https://upload.wikimedia.org/wikipedia/commons/a/a7/Prague_%286365119737%29.jpg",
     },
      {
        "type":"weather", 
        "width":"500", 
        "location":"Praha,cz",
        "backgroundImage": "https://upload.wikimedia.org/wikipedia/commons/a/a7/Prague_%286365119737%29.jpg",
        "textColor": "white"
      }
    ]
  }, 
  {
    "height":"20%", 
    "items": [
     {
       "type":"weather", 
       "width":"30%", 
       "location":"Olomouc,cz",
       "backgroundImage": "https://upload.wikimedia.org/wikipedia/commons/thumb/9/9a/Olomouc-Horn%C3%AD_náměst%C3%AD.JPG/250px-Olomouc-Horn%C3%AD_náměst%C3%AD.JPG",
       "textColor": "white"
     },
     {
       "type":"weather", 
       "width":"200", 
       "location":"Brno,cz",
       "backgroundImage": "https://upload.wikimedia.org/wikipedia/commons/thumb/b/bf/Josefská_street_in_Brno_I.jpg/170px-Josefská_street_in_Brno_I.jpg",
       "textColor": "white"
     }
    ]
  }, 
  {
    "height":"30%", 
    "items": [
     {
       "type":"weather", 
       "width":"300", 
       "location":"Zlin,cz",
       "backgroundImage":"https://upload.wikimedia.org/wikipedia/commons/thumb/9/98/Zlin-CZ.jpg/800px-Zlin-CZ.jpg"
     },
     {
        "type":"rates", 
        "width":"500", 
        "baseCurrency":"EUR",
        "targetCurrency":"CZK",
        "backgroundImage": "https://upload.wikimedia.org/wikipedia/commons/0/0b/Euro_Series_Banknotes_%282019%29.jpg",
        "textColor": "black"
      }
  ]}
]}
```
