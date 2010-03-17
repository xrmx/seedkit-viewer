/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * seedkit-webkit.c
 * Copyright (C) The SeedKit team. 2010 <scaroo@gmail.com>
 * 
 * SeedKit is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * SeedKit is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <config.h>

#include <gtk/gtk.h>
#include <seed/seed.h>
#include <webkit/webkit.h>


void window_object_cleared (WebKitWebView  *web_view,
                            WebKitWebFrame *frame,
                            gpointer        context,
                            gpointer        arg3,
                            gpointer        user_data) {
    
	SeedEngine *eng;
	eng = seed_init_with_context(NULL, NULL, context);	

	gchar *script_uri = user_data;							
	if (script_uri != NULL) {
		printf("Evaluating %s", script_uri);
		SeedScript* script = seed_script_new_from_file (eng->context, script_uri);
		seed_evaluate(eng->context, script, 0);
	}
}


GtkWidget* create_web_view(gchar* file_uri) {
	GtkWidget *web_view = webkit_web_view_new ();
	g_signal_connect(G_OBJECT(web_view), "window-object-cleared", 
                      G_CALLBACK(window_object_cleared), NULL);
	
	webkit_web_view_open (WEBKIT_WEB_VIEW(web_view), file_uri);
	return web_view;
}
