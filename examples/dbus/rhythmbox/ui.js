Seed.include("./dbus-rhythmbox.js");

//$(document).ready(function(){


//var shell = new RhythmboxShell();
var player = new RhythmboxPlayer();

player.getVolumeRemote(function (volume) {print("oi")});


mainloop = GLib.main_loop_new();
GLib.main_loop_run(mainloop);

/*
$("#next-button").click(function(){
	r.nextRemote();
});

$("#prev-button").click(function(){
	r.previousRemote();
});


r.connect("playingUriChanged", 
	       function(emitter, uri){
		var song = shell.getSongPropertiesRemoteSync(uri);
		print(song);	
	       });

r.connect("playingSongPropertyChanged", 
	       function(emitter, title, property_name, old_value, new_value){
		if (property_name == "rb:coverArt-uri")
			$("#cover-art").attr('src', new_value);

});
*/
//});

