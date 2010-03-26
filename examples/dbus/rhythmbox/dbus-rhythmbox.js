Seed.include("./dbus-local.js");
GLib = imports.gi.GLib;

function RhythmboxShell() {
    this._init();
}
RhythmboxShell.prototype = {
    _init: function() {
	session.proxifyObject (this, 
				   'org.gnome.Rhythmbox',
				   '/org/gnome/Rhythmbox/Shell');
    }
};



var RhythmboxShellIface = {
    name: 'org.gnome.Rhythmbox.Shell',
    methods: [
    { name: 'getSongProperties', inSignature: 's', outSignature: 'a{sv}' },],
    signals: []
};

proxifyPrototype (RhythmboxShell.prototype, RhythmboxShellIface);


function RhythmboxPlayer() {
    this._init();
}
RhythmboxPlayer.prototype = {
    _init: function() {
	session.proxifyObject (this, 
				   'org.gnome.Rhythmbox',
				   '/org/gnome/Rhythmbox/Player');
    }
};



var RhythmboxPlayerIface = {
    name: 'org.gnome.Rhythmbox.Player',
    methods: [
    { name: 'getMute', inSignature: '', outSignature: 'b' },
    { name: 'getVolume', inSignature: '', outSignature: 'd' },
    { name: 'getPlayingUri', inSignature: '', outSignature: 's' },
	{ name: 'next', inSignature: '', outSignature: '' },
	{ name: 'previous', inSignature: '', outSignature: '' },
	],
	signals: [
	{ name: 'playingUriChanged', inSignature: '', outSignature: 's' },
   { name: 'playingSongPropertyChanged', inSignature: '', outSignature: 'ssvv' }
	]
};

proxifyPrototype (RhythmboxPlayer.prototype, RhythmboxPlayerIface);


$(document).ready(function(){
var shell = new RhythmboxShell();
var r = new RhythmboxPlayer();

$("#next-button").click(function(){
	r.nextRemote();
});

$("#prev-button").click(function(){
	r.previousRemote();
});

r.connect("playingUriChanged", 
	       function(emitter, uri){
		$('#file-uri').text(uri);
	       });

r.connect("playingSongPropertyChanged", 
	       function(emitter, title, property_name, old_value, new_value){
		if (property_name == "rb:coverArt-uri")
			$("#cover-art").attr('src', new_value);

});
});



