/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.c
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
#include <seed/seed.h>


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

#include "seedkit-gtk.h"
#include "seedkit-webkit.h"
#include "seedkit-inspector.h"

#define SEEDKIT_DEFAULT_UI_PATH "./ui.html"
#define SEEDKIT_DEFAULT_INIT_PATH "./init.js"

static gboolean inspector = FALSE;
static gboolean menu = FALSE;
static gchar* script_path = NULL;
static gchar** filenames = NULL;

static GOptionEntry entries[] = 
{
  { "inspector", 'i', 0, G_OPTION_ARG_NONE, &inspector, "Display WebKit inspector", NULL },
  { "script", 's', 0, G_OPTION_ARG_STRING, &script_path, "An initializer script. Has full access to low level APIs.", "" },
  { "menu", 'm', 0, G_OPTION_ARG_NONE, &menu, "Provide integration with a native menu.", NULL },
  {G_OPTION_REMAINING, 0, 0, G_OPTION_ARG_FILENAME_ARRAY, &filenames, "Balbalbal", NULL},
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

gchar* get_file_uri(gchar* file_path, GError* error) {

	if (file_path == NULL)
		return NULL;
	gchar* current_dir = g_get_current_dir();
	gchar* absolute_filename =  g_strdup_printf("%s/%s", current_dir, file_path);
	g_free(current_dir);
	gchar* file_uri = g_filename_to_uri (absolute_filename, NULL, &error);
	g_free(absolute_filename);

	return file_uri;
}

int
main (int argc, char *argv[])
{
 	GtkWidget *window;
	GError *error;

#ifdef ENABLE_NLS
	bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);
#endif
	
	goption_init(argc, argv, error);
	gtk_set_locale ();
	g_thread_init(NULL);
	gdk_threads_init();       
   
	gtk_init (&argc, &argv);
	
	gchar* file_uri = get_file_uri (filenames ==  NULL ? SEEDKIT_DEFAULT_UI_PATH : filenames[0], error);

	//gchar* script_uri = get_file_uri (script_path ==  NULL ? NULL : script_path, error);

	window = create_window (file_uri, script_path, inspector, menu);
	g_free(file_uri);
	gtk_widget_show_all (window);
	gtk_main ();
	return 0;
}
