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


lib_LTLIBRARIES = libseedkit-1.0.la

libseedkit_clientincludedir = $(includedir)/seedkit-1.0/libseedkit
libseedkit_clientinclude_HEADERS = seedkit-view.h
libseedkit_1_0_la_SOURCES = \
	seedkit-view.h \
	seedkit-view.c

libseedkit_1_0_la_LDFLAGS = 	\
	-export-symbols-regex '^seedkit_.*'

libseedkit_1_0_la_LIBADD = $(SEEDKIT_LIBS)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = seedkit-1.0.pc

DISTCLEANFILES = *~

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(datadir)/seedkit
