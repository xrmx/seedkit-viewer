Notify = imports.gi.Notify;

function sendNotification(summary, body, timeOut) {
	var notification = new Notify.Notification({summary:summary, body:body});
	notification.set_timeout(timeOut);
	notification.show();
}

$(document).ready(function(){

	Notify.init("Webview");

	$("#notification-button").click( function() {
		sendNotification("Raised from a SeedKit View.","Yes, it is.", 500);	
	});
});


