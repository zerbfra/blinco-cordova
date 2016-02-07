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

The plugin provides two different APIs in order to achieve different functionalities. 

1. Blinco: provides nearby device detection
2. BlincoComm: provides communication between devices

### Blinco initialitazion

In order to use Blinco, you need to provide a configuration dictionary:

```javascript
    var cnfg = {"app_name":"your_app_name",
                "app_id":"01b54b58-a3ce-4e32-8947-7c384e9be995",
                "app_secret":"b12868fe25a322726219017528d9873b97d8e0b1a90ea954923b050da0b54507",
                "ble_service":"d8409b48-d49b-47f2-9844-a19ea7b10bc0" };
```

You can decide your own app name but you must register on the blinco server in order to get a new app_id, app_secret and ble_service uuid.

Then, you can init the Blinco framework instance by calling the method:

```javascript
    Blinco.init(cnfg, function(message) {
        console.log(message);
        // handle framework start (here you can call Blinco.start)
    }, function(message) {
        // handle fail (print message)
    });
    
```

### Blinco start

After initializing, you can start the framework via:

```javascript
    Blinco.start(function(message) {
        console.log("info: blinco detected devices are -> "+JSON.stringify(message));
    }, null);
```

Please note that the successCallback function is called every time a new device is discovered, supplying an incremental array of devices.

### Blinco stop

If you need to stop the discovery process, you can call:

```javascript
    Blinco.stop(function(message) {
        console.log("info: blinco stopped");
    }, null);
```  

### Blinco reset

You can reset the discovered devices by calling the reset API. Keep in mind that by resettin Blinco, you will lose all previously scanned devices.
After calling reset, a new call to the start successCallback function is made if some devices are discovered.
This is really helpful when your user change it's position and you need to flush all the old discovered devices.

```javascript
    Blinco.reset(function(message) {
        console.log("info: blinco resetted");
    }, null);
```

### BlincoComm connection

To connect to the Blinco communication framework, start listening on the device channel. 
Every time your device will receive a payload from another device, the successCallback function will be called (as in the example below).

```javascript
    BlincoComm.listen(function(payload) {
        console.log("info: blinco communication received ->"+JSON.stringify(payload));
    }, null);
```

### BlincoComm send payload

Before sending a payload to another device you must declare it. Every payload is composed of a target id that's the receiver of the message and the message itself (only strings are allowed).

```javascript
    var payload = {"target":"56b7116327a4b0f604fabfb4",
                   "message":"testing messages"
                  };
```

To send the payload, simply:

```javascript
    BlincoComm.send(payload,function(message) {
        console.log(message);
    }, function(message) {
        console.log(message);
    });
```