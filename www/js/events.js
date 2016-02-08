
function initBlinco(callback) {

    var cnfg = {"app_name":"meethere",
                "app_id":"01b54b58-a3ce-4e32-8947-7c384e9be995",
                "app_secret":"b12868fe25a322726219017528d9873b97d8e0b1a90ea954923b050da0b54507",
                "ble_service":"d8409b48-d49b-47f2-9844-a19ea7b10bc0" };

    Blinco.init(cnfg, function(message) {
        console.log(message);

        startBlinco();

    }, function(message) {
        console.log(message);
    });
}

function startBlinco() {
    Blinco.start(function(result) {
        console.log("info: blinco detected devices are -> "+JSON.stringify(result));

        var html = "";

        result.forEach(function(entry) {
            html += '<li class="table-view-cell">'+entry["deviceID"]+'<button class="btn btn-primary" data-target="'+entry["deviceID"]+'">Alert</button></li>';

        });


        console.log(html);
        $("#devices").html(html);

    }, null);
}

function stopBlinco() {
    Blinco.stop(function(message) {
        console.log("info: blinco stopped");
    }, null);
}

function resetBlinco() {
    Blinco.reset(function(message) {
        console.log("info: blinco resetted");
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

    BlincoComm.send(payload,function(message) {
        console.log(message);
    }, function(message) {
        console.log(message);
    });
}

(function(window){

    $('#start').click(function(){

        initBlinco(function() {
            startBlinco();
        });

    });

    $('#stop').click(function(){

        stopBlinco();

    });

    $('#reset').click(function(){

        resetBlinco();

    });

    $('#listen').click(function(){

        listenPush();

    });



    $( "#devices" ).on( "click", "li button", function() {
        console.log("clicked");
        var target = $(this).data('target');

        var msg = prompt("Message:", "Ciao!");
        sendPush(target,msg);

    });





})(window);
