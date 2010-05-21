/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * seedkit
 * Copyright (C) Alexandre Mazari 2010 <scaroo@gmail.com>
 * 
 * seedkit is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later fversion.
 * 
 * seedkit is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SEEDKIT_VIEW_H_
#define _SEEDKIT_VIEW_H_

#include <glib-object.h>
#include <gtk/gtk.h>
#include <seed/seed.h>
#include <webkit/webkit.h>


G_BEGIN_DECLS

#define SEEDKIT_TYPE_VIEW             (seedkit_view_get_type ())
#define SEEDKIT_VIEW(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), SEEDKIT_TYPE_VIEW, SeedKitView))
#define SEEDKIT_VIEW_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), SEEDKIT_TYPE_VIEW, SeedKitViewClass))
#define SEEDKIT_IS_VIEW(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SEEDKIT_TYPE_VIEW))
#define SEEDKIT_IS_VIEW_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), SEEDKIT_TYPE_VIEW))
#define SEEDKIT_VIEW_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), SEEDKIT_TYPE_VIEW, SeedKitViewClass))

typedef struct _SeedKitViewClass SeedKitViewClass;
typedef struct _SeedKitView SeedKitView;

struct _SeedKitViewClass
{
	WebKitWebViewClass parent_class;

};

struct _SeedKitView
{
	WebKitWebView parent_instance;

};

#define SEEDKIT_VIEW_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), SEEDKIT_TYPE_VIEW, SeedKitViewPrivate))
typedef struct _SeedKitViewPrivate SeedKitViewPrivate;
struct _SeedKitViewPrivate {
	SeedEngine *seed_engine;
};

GType seedkit_view_get_type (void) G_GNUC_CONST;


SeedKitView* seedkit_view_new (void);

G_END_DECLS

#endif /* _SEEDKIT_VIEW_H_ */
