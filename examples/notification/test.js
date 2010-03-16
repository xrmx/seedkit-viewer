
function sendNotification(summary, body, timeOut) {
	var notification = new Notify.Notification({summary:summary, body:body});
	notification.set_timeout(timeOut);
	notification.show();
}

$(document).ready(function(){

Notify = imports.gi.Notify;

Notify.init("Webview");

$("#notification-button").click( function() {
	sendNotification("Raised from a WebView","Raised from a WebView", 500);	
	Seed.print("clicked");
});




});


