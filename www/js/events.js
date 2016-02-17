
function initBlinco(callback) {

    var cnfg = {"app_name":"meethere",
                "app_id":"01b54b58-a3ce-4e32-8947-7c384e9be995",
                "app_secret":"b12868fe25a322726219017528d9873b97d8e0b1a90ea954923b050da0b54507",
                "ble_service":"d8409b48-d49b-47f2-9844-a19ea7b10bc0" };

    Blinco.init(cnfg, function(init_info) {
        console.log(JSON.stringify(init_info));
        // ok, blinco initialized - print device id and start
        $("#me").html('<center>Device ID: '+init_info["device_id"]+'</center>');
        startBlinco();

    }, function(error) {
        console.log(error);
    });
}

function startBlinco() {
    Blinco.start(function(result) {
        console.log("info: blinco detected devices are -> "+JSON.stringify(result));

        var html = "";

        result.forEach(function(entry) {
            html += '<li class="table-view-cell">'+entry["deviceID"]+'<button class="btn btn-primary" data-target="'+entry["deviceID"]+'">Alert</button></li>';
        });

        $("#devices").html(html);

    }, null);
}

function stopBlinco() {
    Blinco.stop(function(success) {
        console.log(success);
    }, null);
}

function resetBlinco() {
    Blinco.reset(function(success) {
        console.log(success);
        // reset the list
        $("#devices").html("No nearby devices");
    }, null);
}

function listenPush() {
    BlincoComm.listen(function(payload) {
        console.log("info: blinco communication received ->"+JSON.stringify(payload));
        alert(payload["message"]);
    }, null);
}

function sendPush(target,msg) {

    console.log("info: sending push to "+target);

    var payload = {"target":target,
                   "message": msg
                  };

    BlincoComm.send(payload,function(success) {
        console.log(success);
    }, function(error) {
        console.log(error);
    });
}

(function(window){

    $('#start').click(function(){
        initBlinco(function() {
            startBlinco();
        });
    });

    $('#stop').click(function(){ stopBlinco(); });
    $('#reset').click(function(){ resetBlinco(); });
    $('#listen').click(function(){ listenPush(); });

    $( "#devices" ).on( "click", "li button", function() {
        // get the target device
        var target = $(this).data('target');
        // create a standard message
        var msg = prompt("Message:", "Ciao!");
        sendPush(target,msg);
    });

})(window);
