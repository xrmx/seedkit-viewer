
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



try {
DBus = imports.dbus;
GLib = imports.gi.GLib;
} catch (e) {
	print(dump(e, 2));

}
/*
var r = new Rhythmbox();

r.connect("playingUriChanged", 
	       function(emitter, state){
	       alert(state);
		   //$("file-uri").text(state);
	       });
r.nextRemote();
*/
mainloop = GLib.main_loop_new();
GLib.main_loop_run(mainloop);
