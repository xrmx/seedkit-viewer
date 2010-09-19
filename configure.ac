dnl Process this file with autoconf to produce a configure script.
dnl Created by Anjuta application wizard.
AC_PREREQ([2.63])
AC_INIT([seedkit-viewer],[0.2])

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.11])
AM_MAINTAINER_MODE([enable])

# Support silent build rules. Disable by either passing --disable-silent-rules
# to configure or passing V=1 to make
AM_SILENT_RULES([yes])

# Check for programs
AC_PROG_CC


#Initialize libtool
LT_PREREQ([2.2])
LT_INIT


# Check for libraries
GTK_REQUIRED=2.21.5
SEEDKIT_REQUIRED=0.2

PKG_CHECK_MODULES(SEEDKIT,
	gtk+-2.0 >= $GTK_REQUIRED dnl
        seedkit-1.0    >= $SEEDKIT_REQUIRED
	
)

# Expose requirements for using in spec and pc file
AC_SUBST(GTK_REQUIRED)
AC_SUBST(SEEDKIT_REQUIRED)


dnl ***************************************************************************
dnl Internatinalization
dnl ***************************************************************************
IT_PROG_INTLTOOL([0.41.0])

GETTEXT_PACKAGE=seedkit-viewer
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [GETTEXT package name])
AM_GLIB_GNU_GETTEXT

##################################################
# Check for gtk-doc.
##################################################
AC_ARG_WITH(html-dir, [  --with-html-dir=PATH path to installed docs ])
if test "x$with_html_dir" = "x" ; then
  HTML_DIR='${datadir}/gtk-doc/html'
else
  HTML_DIR=$with_html_dir
fi
AC_SUBST(HTML_DIR)

gtk_doc_min_version=1.0
AC_MSG_CHECKING([gtk-doc version >= $gtk_doc_min_version])
if pkg-config --atleast-version=$gtk_doc_min_version gtk-doc; then
  AC_MSG_RESULT(yes)
  GTKDOC=true
else
  AC_MSG_RESULT(no)
  GTKDOC=false
fi
dnl Let people disable the gtk-doc stuff.
AC_ARG_ENABLE(gtk-doc,
              [  --enable-gtk-doc  Use gtk-doc to build documentation [default=auto]],
	      enable_gtk_doc="$enableval", enable_gtk_doc=auto)
if test x$enable_gtk_doc = xauto ; then
  if test x$GTKDOC = xtrue ; then
    enable_gtk_doc=yes
  else
    enable_gtk_doc=no
  fi
fi
AM_CONDITIONAL(ENABLE_GTK_DOC, test x$enable_gtk_doc = xyes)


AC_CONFIG_FILES([
Makefile
src/Makefile
src/seedkit-viewer/Makefile
po/Makefile.in
data/Makefile
debian/control
])
AC_OUTPUT
