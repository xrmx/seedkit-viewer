Seed.include("./dbus-rhythmbox.js");

$(document).ready(function(){


var shell = new RhythmboxShell();
var player = new RhythmboxPlayer();

//playeplayer.getVolumeRemote(function (volume) {print("oi")});


$("#next-button").click(function(){
	player.nextRemote();
});

$("#prev-button").click(function(){
	player.previousRemote();
});


player.connect("playingUriChanged", 
	       function(emitter, uri){
		//var song = shell.getSongPropertiesRemoteSync(uri);
		//print(song);	
	       });

player.connect("playingSongPropertyChanged", 
	       function(emitter, title, property_name, old_value, new_value){
		if (property_name == "rb:coverArt-uri")
			$("#cover-art").attr('src', new_value);

});

});

