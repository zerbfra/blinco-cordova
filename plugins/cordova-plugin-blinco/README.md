#cordova-blinco-plugin

> This plugin allows your application to handle the iOS Blinco Framework.

## Installation

WIP


## Supported Platforms

- iOS

## Quick Example

```javascript
        var success = function(message) {
            alert(message);
        };

        var failure = function(message) {
            alert(message);
        };

        var cnfg = {"app_name":"your_app_name",
                    "app_id":"your_app_id",
                    "app_secret":"b12868fe25a322726219017528d9873b97d8e0b1a90ea954923b050da0b54507",
                    "ble_service":"d8409b48-d49b-47f2-9844-a19ea7b10bc0" };

        var blinco = Blinco.init(cnfg, success, failure);
```

## API

WIP