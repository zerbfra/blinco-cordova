var blinco = {

    /**
    * Init the blinco framework
    * @param {dictionary} config - the configuration dictionary for the framework
    * config takes 4 mandatory keys: app_name, app_id, app_secret and ble_service
    */
    init: function (config, successCallback, errorCallback) {

        console.log("info: init blinco");
        cordova.exec(successCallback,errorCallback,"Blinco","init",[ config ]);
    },

    /** Start detection of nearby devices, return an array of device objects (use JSON) */
    start: function (successCallback, errorCallback) {
        console.log("info: starting blinco");
        cordova.exec(successCallback,errorCallback,"Blinco","start",[ ]);
    },

    /** Stop detection of nearby devices */
    stop: function (successCallback, errorCallback) {
        console.log("info: stopping blinco");
        cordova.exec(successCallback,errorCallback,"Blinco","stop",[ ]);
    },

    /** Reset discovered devices, if start was previously called, after resetting it refresh the available nearby devices */
    reset: function (successCallback, errorCallback) {
        console.log("info: resetting blinco");
        cordova.exec(successCallback,errorCallback,"Blinco","reset",[ ]);
    }

};

module.exports = blinco;
