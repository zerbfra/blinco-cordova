var blincopush = {

    /**
    * Init the blinco framework
    * @param {dictionary} config - the configuration dictionary for the framework
    * config takes 4 mandatory keys: app_name, app_id, app_secret and ble_service
    */
    listen: function (successCallback, errorCallback) {

        console.log("info: init blinco push");
        cordova.exec(successCallback,errorCallback,"BlincoComm","connect",[ ]);
    },

    /** Start detection of nearby devices, return an array of device objects (use JSON) */
    send: function (data,successCallback, errorCallback) {
        console.log("info: sending blinco payload");
        cordova.exec(successCallback,errorCallback,"BlincoComm","send",[ data ]);
    }

};

module.exports = blincopush;
