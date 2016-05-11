# m4_esyscmd_s for autoconf < 2.64
m4_ifndef([m4_esyscmd_s], [m4_define([m4_esyscmd_s], [m4_chomp_all(m4_esyscmd([$1]))])])
m4_ifndef([m4_chomp_all], [m4_define([m4_chomp_all], [m4_format([[%.*s]], m4_bregexp(m4_translit([[$1]], [
/], [/ ]), [/*$]), [$1])])])

m4_define([my_version],
  m4_esyscmd_s([
    if test -f .version; then
      cat .version;
    else
      scripts/git-version-gen.sh -C . -v;
    fi
  ])dnl
)

AC_PREREQ([2.59])
AC_INIT([test], [my_version])
AC_CONFIG_SRCDIR([test.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([1.7 foreign -Wall])

AC_PROG_LN_S
AC_PROG_CC

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
