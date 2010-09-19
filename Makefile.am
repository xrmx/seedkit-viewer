## Process this file with automake to produce Makefile.in
## Created by Anjuta
ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

SUBDIRS = src po data

seedkitdocdir = ${prefix}/doc/seedkit-viewer
seedkitdoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


INTLTOOL_FILES = intltool-extract.in \
	intltool-merge.in \
	intltool-update.in

EXTRA_DIST = $(seedkitdoc_DATA) \
	$(INTLTOOL_FILES) \
	examples/* \
	debian/* \
	TODO.tasks

DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache \
	*~

MAINTAINERCLEANFILES = \
	$(srcdir)/INSTALL \
	$(srcdir)/aclocal.m4 \
	$(srcdir)/config.guess \
	$(srcdir)/config.h.in \
	$(srcdir)/config.sub \
	$(srcdir)/depcomp \
	$(srcdir)/install-sh \
	$(srcdir)/ltmain.sh \
	$(srcdir)/missing \
	$(srcdir)/mkinstalldirs \
	`find "$(srcdir)" -type f -name Makefile.in -print` \
	$(srcdir)/configure \
	$(srcdir)/gtk-doc.make \
	$(srcdir)/m4/gtk-doc.m4 \
	$(srcdir)/m4/intltool.m4

-include $(top_srcdir)/git.mk


# Remove doc directory on uninstall
uninstall-local:
#	-rm -r $(seedkitdocdir)
