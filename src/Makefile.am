## Process this file with automake to produce Makefile.in

## Created by Anjuta

uidir = $(datadir)/seedkit/ui
ui_DATA = seedkit.ui

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	$(SEEDKIT_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = seedkit

seedkit_SOURCES = \
	callbacks.c \
	callbacks.h \
	main.c

seedkit_LDFLAGS = \
	-Wl,--export-dynamic

seedkit_LDADD = $(SEEDKIT_LIBS)

EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(datadir)/seedkit
