var blincopush = {

    /**
    * Listen for blinco notifications
    * Once started the successCallback will be called every time there's a notification
    */
    listen: function (successCallback, errorCallback) {

        console.log("info: init blinco push");
        cordova.exec(successCallback,errorCallback,"BlincoComm","connect",[ ]);
    },

    /**
    * Send data to another device
    * @param {dictionary} data - the payload dictionary to send
    **/
    send: function (data,successCallback, errorCallback) {
        console.log("info: sending blinco payload");
        cordova.exec(successCallback,errorCallback,"BlincoComm","send",[ data ]);
    }

};

module.exports = blincopush;
