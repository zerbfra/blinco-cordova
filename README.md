#cordova-blinco-plugin

> This plugin allows your application to handle the iOS Blinco Framework.

_Please refer to [the plugin documentation](plugins/cordova-plugin-blinco) for detailed API._
_This documentations refers to the example contained in the www directory._

## Usage

The example is composed of 2 main files:

- index.html (the main page layout)
- js/events.js (actions)

In particular, you will find 3 buttons to start,stop,reset the nearby devices discovery + un more button to connect the framework to the communication channel.

In index.html there's also a div that is populated with the current nearby devices.

The javascript file catch all the jquery events of the page and acts on the framework.

Keep in mind that, every function called on the Blinco framework has this structure:

```javascript
    Blinco.init(cnfg, function(success) {
        // this is the success callback function
        console.log(success); // message contains log from the framework

    }, function(error) {
        // this is the error callback function
        console.log(error); // message contains the error string
    });
```

In some cases, the error callback function can be null (for istance on the stop function).