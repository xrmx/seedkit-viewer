DBus = imports.dbus;
GLib = imports.gi.GLib;

function Rhythmbox() {
    this._init();
}
Rhythmbox.prototype = {
    _init: function() {
	DBus.session.proxifyObject (this, 
				   'org.gnome.Rhythmbox',
				   '/org/gnome/Rhythmbox/Player');
    }
};



var RhythmboxIface = {
    name: 'org.gnome.Rhythmbox.Player',
    methods: [
    { name: 'getMute', inSignature: '', outSignature: 'b' },
    { name: 'getVolume', inSignature: '', outSignature: 'd' },
    { name: 'getPlayingUri', inSignature: '', outSignature: 's' },
	{ name: 'next', inSignature: '', outSignature: '' },
	{ name: 'previous', inSignature: '', outSignature: '' },
	],
	signals: [
	{ name: 'playingUriChanged', inSignature: '', outSignature: 's' }
   
	]
};

DBus.proxifyPrototype (Rhythmbox.prototype, RhythmboxIface);

var r = new Rhythmbox();

r.connect("playingUriChanged", 
	       function(emitter, state){
	       alert(state);
		   //$("file-uri").text(state);
	       });
r.nextRemote();

mainloop = GLib.main_loop_new();
GLib.main_loop_run(mainloop);