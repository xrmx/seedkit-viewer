/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * seedkit-webkit.c
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

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <config.h>

#include <gtk/gtk.h>
#include <seed.h>
#include <webkit/webkit.h>
#include <seedkit-view.h>



WebKitWebView* create_web_view(gchar* file_uri, gchar* script_uri) {
	WebKitWebView *web_view = WEBKIT_WEB_VIEW(seedkit_view_new ());
	webkit_web_view_load_uri (web_view, file_uri);
	return web_view;
}
