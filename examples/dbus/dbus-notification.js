#!/usr/bin/env seed
DBus = imports.dbus;
GLib = imports.gi.GLib;

function Notification() {
    this._init();
}
Notification.prototype = {
    _init: function() {
	DBus.session.proxifyObject (this, 
				   'org.freedesktop.Notifications',
				   '/org/freedesktop/Notifications');
    }
};



var NotificationIface = {
    name: 'org.freedesktop.Notifications',
    methods: [
	{ name: 'Notify', inSignature: 'susssasa{sv}i', outSignature: 'u' }
    ]
};


DBus.proxifyPrototype (Notification.prototype, NotificationIface);
var notification = new Notification();
notification.NotifyRemote("SeedKit", 42,"","SeedKit sent notification","Via DBus",[],{}, 5000);
mainloop = GLib.main_loop_new();
GLib.main_loop_run(mainloop);
