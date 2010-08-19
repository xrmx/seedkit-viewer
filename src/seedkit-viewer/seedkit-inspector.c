/*
 * seedkit-inspector.c
 * Copyright (C) The SeedKit team. 2010 <seedkit-list@gnome.org>
 * 
 * SeedKit is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * SeedKit is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>
#include <seed/seed.h>
#include <webkit/webkit.h>

WebKitWebView*  add_inspector_to_container (WebKitWebInspector *web_inspector,
                                         WebKitWebView      *web_view,
                                         gpointer            hbox)
{	  
    GtkWidget *inspector_view = webkit_web_view_new ();
	gtk_container_add (GTK_CONTAINER(hbox), inspector_view);
	
	return WEBKIT_WEB_VIEW(inspector_view);
}

WebKitWebInspector*
create_inspector (WebKitWebView* web_view, GtkContainer* container) { 
    WebKitWebSettings *settings = webkit_web_view_get_settings(WEBKIT_WEB_VIEW(web_view));
	g_object_set (G_OBJECT (settings),
              "enable-developer-extras", TRUE,   
              NULL);

	WebKitWebInspector *inspector = webkit_web_view_get_inspector (WEBKIT_WEB_VIEW(web_view));
	g_signal_connect (G_OBJECT (inspector), "inspect-web-view", 
			  G_CALLBACK(add_inspector_to_container), container);

	return inspector;
}


