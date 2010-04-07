void goption_init(int argc, char *argv[], GError *error);

static gboolean inspector = FALSE;
static gchar* script_uri = "file://./init.js";
static gchar** filenames = {"ui.html", NULL};

static GOptionEntry entries[] = 
{
  { "inspector", 'i', 0, G_OPTION_ARG_NONE, &inspector, "Display WebKit inspector", NULL },
  { "script", 's', 0, G_OPTION_ARG_STRING, &script_uri, "An initializer script. Has full access to low level APIs.", "" },
	{G_OPTION_REMAINING, 0, 0, G_OPTION_ARG_FILENAME_ARRAY, &filenames, "Balbalbal", NULL},
{ NULL }
};