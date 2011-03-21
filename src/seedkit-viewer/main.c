/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.c
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
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <config.h>

#include <gtk/gtk.h>
#include <webkit/webkit.h>
#include <seed.h>

#include "seedkit-viewer.h"
#include "seedkit-gtk.h"
#include "seedkit-webkit.h"
#include "seedkit-inspector.h"

/*
 * Standard gettext macros.
 */
#ifdef ENABLE_NLS
#  include <libintl.h>
#  undef _
#  define _(String) dgettext (PACKAGE, String)
#  ifdef gettext_noop
#    define N_(String) gettext_noop (String)
#  else
#    define N_(String) (String)
#  endif
#else
#  define textdomain(String) (String)
#  define gettext(String) (String)
#  define dgettext(Domain,Message) (Message)
#  define dcgettext(Domain,Message,Type) (Message)
#  define bindtextdomain(Domain,Directory) (Domain)
#  define _(String) (String)
#  define N_(String) (String)
#endif


#define SEEDKIT_DEFAULT_UI_PATH "./ui.html"
#define SEEDKIT_DEFAULT_INIT_PATH "./init.js"


static SeedKitViewerSettings seedkit_viewer_settings = {FALSE, FALSE, FALSE, NULL, NULL};

static GOptionEntry entries[] = 
{
  { "inspector", 'i', 0, G_OPTION_ARG_NONE, &(seedkit_viewer_settings.inspector), "Display WebKit inspector", NULL },
  { "widget", 'i', 0, G_OPTION_ARG_NONE, &(seedkit_viewer_settings.widget), "Widget mode : no window decorations, ARGB color map.", NULL },
  { "script", 's', 0, G_OPTION_ARG_STRING, &(seedkit_viewer_settings.script_path), "An initializer script. Has full access to low level APIs.", "" },
  { "menu", 'm', 0, G_OPTION_ARG_NONE, &(seedkit_viewer_settings.menu), "Provide integration with a native menu.", NULL },
  {G_OPTION_REMAINING, 0, 0, G_OPTION_ARG_FILENAME_ARRAY, &(seedkit_viewer_settings.filenames), "Balbalbal", NULL},
  { NULL }
};

void goption_init(int argc, char *argv[],GError *error)
{
	GOptionContext *context;
	
	context = g_option_context_new ("- test tree model performance");
	g_option_context_add_main_entries (context, entries, GETTEXT_PACKAGE);
	g_option_context_add_group (context, gtk_get_option_group (TRUE));
	if (!g_option_context_parse (context, &argc, &argv, &error))
    {
      g_print ("option parsing failed: %s\n", error->message);
      exit (1);
    }
}

gchar* get_file_uri (gchar* file_path, GError* error) {
	if (file_path == NULL)
		return NULL;

	gchar* uri =  g_strdup_printf ("file://%s\n", file_path);
	return uri;
}

int
main (int argc, char *argv[])
{
 	GtkWidget *window;
	GError *error = NULL;
	GFile *ui_file;

#ifdef ENABLE_NLS
	bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);
#endif
	
	goption_init(argc, argv, error);
	g_thread_init(NULL);
	gdk_threads_init();       
   
	gtk_init (&argc, &argv);
	
	ui_file = g_file_new_for_commandline_arg (seedkit_viewer_settings.filenames ==  NULL ? SEEDKIT_DEFAULT_UI_PATH : seedkit_viewer_settings.filenames[0]);
	gchar* file_uri = g_file_get_uri (ui_file);
	g_assert_no_error(error);
	
	window = create_window (file_uri, &seedkit_viewer_settings);
	g_free(file_uri);
	gtk_widget_show_all (window);
	gtk_main ();
	return 0;
}
