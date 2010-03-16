WebKitWebInspector*
create_inspector (WebKitWebView* web_view, GtkContainer* container);

WebKitWebView*  add_inspector_to_window (WebKitWebInspector *web_inspector,
                                         WebKitWebView      *web_view,
                                         gpointer            hbox);