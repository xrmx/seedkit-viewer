
function sendNotification(summary, body, timeOut) {
	var notification = new Notify.Notification({summary:summary, body:body});
	notification.set_timeout(timeOut);
	notification.show();
}

function readFile(path) {
	var inputFile = Gio.file_new_for_path(path);
	var fstream = inputFile.read();
	var dstream = new Gio.DataInputStream.c_new(fstream);
	var line = dstream.read_until("", 0);
	fstream.close();

	return line;
}


function currentlyPlayedSong() {
}

function valueForGconfKey(key) {
 client = GConf.Client.get_default();
 return client.get_string(key);
}

function dump(arr,level) {
	var dumped_text = "";
	if(!level) level = 0;
	
	//The padding given at the beginning of the line.
	var level_padding = "";
	for(var j=0;j<level+1;j++) level_padding += "    ";
	
	if(typeof(arr) == 'object') { //Array/Hashes/Objects 
		for(var item in arr) {
			var value = arr[item];
			
			if(typeof(value) == 'object') { //If it is an array,
				dumped_text += level_padding + "'" + item + "' ...\n";
				dumped_text += dump(value,level+1);
			} else {
				dumped_text += level_padding + "'" + item + "' => \"" + value + "\"\n";
			}
		}
	} else { //Stings/Chars/Numbers etc.
		dumped_text = "===>"+arr+"<===("+typeof(arr)+")";
	}
	return dumped_text;
}



$(document).ready(function(){

DBus = imports.dbus;
GLib = imports.gi.GLib;
Notify = imports.gi.Notify;
GConf = imports.gi.GConf;
Gio = imports.gi.Gio;
RbDBus = imports.rbdbus;


Notify.init("Webview");



$("#notification-button").click( function() {
	sendNotification("Raised from a WebView","Raised from a WebView", 500);	
	Seed.print("clicked")
});

$("#file-chooser").change( function() {
	
	$("#editor").text(readFile($(this).attr("value")));
});

$("#gconf-button").click( function() {
	$("#gconf-value").empty();
	$("#gconf-value").text(valueForGconfKey("/apps/gedit-2/preferences/editor/colors/scheme"));
});

var mainloop = GLib.main_loop_new();
GLib.main_loop_run(mainloop);
});


