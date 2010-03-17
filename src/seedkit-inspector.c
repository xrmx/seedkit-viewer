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
	webkit_web_inspector_show(inspector);

	g_signal_connect (G_OBJECT (inspector), "inspect-web-view", G_CALLBACK(add_inspector_to_container), container);

	return inspector;
}


