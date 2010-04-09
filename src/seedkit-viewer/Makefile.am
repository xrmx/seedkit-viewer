## Process this file with automake to produce Makefile.in

## Created by Anjuta


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	$(SEEDKIT_CFLAGS) -I/usr/include/seedkit-1.0/ -I../

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = seedkit-viewer

seedkit_viewer_SOURCES = \
	main.c \
	seedkit-inspector.c \
	seedkit-inspector.h \
	seedkit-webkit.c \
	seedkit-webkit.h \
	seedkit-gtk.c \
	seedkit-gtk.h 

seedkit_viewer_LDFLAGS = \
	-Wl,--export-dynamic

seedkit_viewer_LDADD = $(SEEDKIT_LIBS) -lseedkit-1.0

DISTCLEANFILES = *~

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(datadir)/seedkit
