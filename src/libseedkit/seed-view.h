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

#ifndef _SEED_VIEW_H_
#define _SEED_VIEW_H_

#include <glib-object.h>
#include <gtk/gtk.h>
#include <seed/seed.h>
#include <webkit/webkit.h>


G_BEGIN_DECLS

#define SEED_TYPE_VIEW             (seed_view_get_type ())
#define SEED_VIEW(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), SEED_TYPE_VIEW, SeedView))
#define SEED_VIEW_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), SEED_TYPE_VIEW, SeedViewClass))
#define SEED_IS_VIEW(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SEED_TYPE_VIEW))
#define SEED_IS_VIEW_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), SEED_TYPE_VIEW))
#define SEED_VIEW_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), SEED_TYPE_VIEW, SeedViewClass))

typedef struct _SeedViewClass SeedViewClass;
typedef struct _SeedView SeedView;

struct _SeedViewClass
{
	WebKitWebViewClass parent_class;

};

struct _SeedView
{
	WebKitWebView parent_instance;

};

#define SEED_VIEW_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), SEED_TYPE_VIEW, SeedViewPrivate))
typedef struct _SeedViewPrivate SeedViewPrivate;
struct _SeedViewPrivate {
	SeedEngine *seed_engine;
};

GType seed_view_get_type (void) G_GNUC_CONST;


SeedView* seed_view_new (void);

G_END_DECLS

#endif /* _SEED_VIEW_H_ */
