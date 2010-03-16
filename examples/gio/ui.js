
function readFile(path) {
	var inputFile = Gio.file_new_for_path(path);
	var fstream = inputFile.read();
	var dstream = new Gio.DataInputStream.c_new(fstream);
	var line = dstream.read_until("", 0);
	fstream.close();

	return line;
}

$(document).ready(function(){

Gio = imports.gi.Gio;

$("#file-chooser").change( function() {	
	$("#editor").text(readFile($(this).attr("value")));
});

});


