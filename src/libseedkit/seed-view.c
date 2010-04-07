/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * seedkit
 * Copyright (C) Alexandre Mazari 2010 <scaroo@gmail.com>
 * 
 * seedkit is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * seedkit is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "seed-view.h"

G_DEFINE_TYPE (SeedView, seed_view, WEBKIT_TYPE_WEB_VIEW);

void window_object_cleared (WebKitWebView  *web_view,
                            WebKitWebFrame *frame,
                            gpointer        context,
                            gpointer        arg3,
                            gpointer        seed_view) {
    
	SEED_VIEW_GET_PRIVATE (seed_view)->seed_engine = seed_init_with_context(NULL, NULL, context);	
					
/*
	gchar *script_uri = user_data;							
	if (script_uri != NULL) {
		printf("Evaluating %s\n", script_uri);
		SeedScript* script = seed_script_new_from_file (eng->context, script_uri);
		seed_evaluate(eng->context, script, 0);
	}
			*/
}



static void
seed_view_init (SeedView *self)
{
	WebKitWebView* web_view = WEBKIT_WEB_VIEW(self);

	WebKitWebSettings *settings = webkit_web_view_get_settings(web_view);
	g_object_set (G_OBJECT (settings),
              "auto-resize-window", TRUE,   
              NULL);
	
	g_signal_connect(G_OBJECT(web_view), "window-object-cleared", 
                      G_CALLBACK(window_object_cleared), self);
}

static void
seed_view_finalize (GObject *object)
{
	/* TODO: Add deinitalization code here */

	G_OBJECT_CLASS (seed_view_parent_class)->finalize (object);
}

static void
seed_view_set_property (GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec)
{
	g_return_if_fail (SEED_IS_VIEW (object));

	switch (prop_id)
	{

	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
		break;
	}
}

static void
seed_view_get_property (GObject *object, guint prop_id, GValue *value, GParamSpec *pspec)
{
	g_return_if_fail (SEED_IS_VIEW (object));

	switch (prop_id)
	{
	
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
		break;
	}
}

static GObject *
seed_view_constructor (GType                  gtype,
                       guint                  n_properties,
                       GObjectConstructParam *properties)
{
  GObject *obj;

  {
    /* Always chain up to the parent constructor */
    GObjectClass *parent_class;  
    parent_class = G_OBJECT_CLASS (seed_view_parent_class);
    obj = parent_class->constructor (gtype, n_properties, properties);
  }
  
  /* update the object state depending on constructor properties */

  return obj;
}


static void
seed_view_class_init (SeedViewClass *klass)
{
	GObjectClass* object_class = G_OBJECT_CLASS (klass);

	/* register private structure */
	g_type_class_add_private(klass, sizeof(SeedViewPrivate));
	
	object_class->constructor = seed_view_constructor;
	object_class->finalize = seed_view_finalize;
	object_class->set_property = seed_view_set_property;
	object_class->get_property = seed_view_get_property;

	
}

SeedView* seed_view_new () {
	return SEED_VIEW (g_object_new (SEED_TYPE_VIEW, NULL));
}
