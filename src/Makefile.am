## Process this file with automake to produce Makefile.in

## Created by Anjuta


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
	main.c \
	seedkit-inspector.c \
	seedkit-inspector.h \
	seedkit-webkit.c \
	seedkit-webkit.h \
	seedkit-gtk.c \
	seedkit-gtk.h

seedkit_LDFLAGS = \
	-Wl,--export-dynamic

seedkit_LDADD = $(SEEDKIT_LIBS)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(datadir)/seedkit
