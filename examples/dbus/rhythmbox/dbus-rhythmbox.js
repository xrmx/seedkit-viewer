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
    { name: 'quit', inSignature: '', outSignature: '' },
    { name: 'getSongProperties', inSignature: 's', outSignature: 'a\{sv\}' },],
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

