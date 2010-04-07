Seed.include("./dbus-local.js");
GLib = imports.gi.GLib;

function TrackerResource() {
    this._init();
}
TrackerResource.prototype = {
    _init: function() {
	session.proxifyObject (this, 
				   'org.freedesktop.Tracker1',
				   '/org/freedesktop/Tracker1/Resources');
    }
};



var TrackerResourceIface = {
    name: 'org.freedesktop.Tracker1.Resources',
    methods: [
    { name: 'SparqlQuery', inSignature: 's', outSignature: 'aas' },],
    signals: []
};

proxifyPrototype (TrackerResource.prototype, TrackerResourceIface);
