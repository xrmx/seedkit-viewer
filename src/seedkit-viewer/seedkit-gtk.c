/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * seedkit-gtk.c
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
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <config.h>

#include <gtk/gtk.h>
#include <webkit/webkit.h>

#include "seedkit-viewer.h"
#include "seedkit-webkit.h"
#include "seedkit-inspector.h"

void
destroy (GtkWidget *widget, gpointer data)
{
	gtk_main_quit ();
}


void set_window_title (WebKitWebView  *web_view,
                       WebKitWebFrame *frame,
                       gchar          *title,
                       gpointer        user_data){


    gtk_window_set_title(GTK_WINDOW(user_data), title);  
}

GtkWidget*
create_window (gchar* file_uri, SeedKitViewerSettings* settings)
{
	GtkWidget *window;

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

	gtk_window_set_default_size (GTK_WINDOW(window), 800, 600);
	g_signal_connect (G_OBJECT (window), "destroy",
                      G_CALLBACK (destroy), NULL);
	GtkWidget* vbox = gtk_vpaned_new();

	if (settings->menu == TRUE) {
		// TODO, expose the menu instance in seed context
		 GtkWidget* menu = gtk_menu_bar_new();
		gtk_container_add (GTK_CONTAINER(vbox), menu);
	}

	GtkWidget* web_view = create_web_view (file_uri, settings->script_path);
	if (settings->widget == TRUE) {
		GdkScreen* screen = gtk_widget_get_screen (window);
		GdkColormap* argb_colormap = gdk_screen_get_rgba_colormap (screen);
		gtk_widget_set_colormap (window, argb_colormap);
		gtk_window_set_decorated (GTK_WINDOW(window), FALSE);
		webkit_web_view_set_transparent(web_view, TRUE);		

	}

	g_signal_connect(G_OBJECT(web_view), "title-changed", 
                      G_CALLBACK(set_window_title), window);
	gtk_container_add (GTK_CONTAINER(vbox), web_view);
	
	if (settings->inspector == TRUE)
		create_inspector(WEBKIT_WEB_VIEW(web_view), GTK_CONTAINER(vbox));

	
	gtk_container_add (GTK_CONTAINER(window), vbox);
	return window;
}

