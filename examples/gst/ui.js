
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




GLib = imports.gi.GLib;
Gst = imports.gi.Gst;
GObject = imports.gi.GObject;

var unique_id = "test";
var pipeline = new Gst.Pipeline({name: "test"});
var audiosrc = Gst.ElementFactory.make("audiotestsrc", "source" + unique_id);
var audiosink = Gst.ElementFactory.make("alsasink", "sink" + unique_id);
var volume = Gst.ElementFactory.make("volume", "volume" + unique_id);

print(pipeline);
//pipeline.add(audiosink);
//pipeline.add(volume);
audiosrc.link_many(volume, audiosink);
 pipeline.set_state(Gst.State.PLAYING);

alert("DEDE");
