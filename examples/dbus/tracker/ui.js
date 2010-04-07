Gtk = imports.gi.Gtk;

Seed.include("./dbus-tracker.js");

//$(document).ready(function(){


var resources = new TrackerResource();


//$("#next-button").click(function(){
	
	try {
		resources.SparqlQueryRemote("SELECT ?s WHERE { ?s rdf:type rdfs:Class . }",
				 function(results){
					print("results");

				});
	} catch (e) {
		print(e.message);
	}
Gtk.main();
	
//});


//});

