AC_PREREQ([2.69])
AC_INIT(guess, [1.0], alinka.kalyakina@yandex.ru)
AM_INIT_AUTOMAKE
DX_INIT_DOXYGEN(guesser)
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_SRCDIR([roman.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

AM_INIT_AUTOMAKE

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h stdlib.h string.h, assert.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

AC_CONFIG_FILES([Makefile
                Doxyfile
                guesser.md
                roman.md])
AC_OUTPUT

define(DATE, `date`)dnl
define(COMMENT_RE, [^\/\* COMMENT::.*\*\/])dnl
define(MY_COMMENT, [\/\* COMMENT:: AC_PACKAGE_NAME, AC_PACKAGE_VERSION: DATE \*\/])dnl
define(SEDPARAM, ["1 s/COMMENT_RE/MY_COMMENT/; t; 1 i\MY_COMMENT;"])dnl

sed -i SEDPARAM *.c 
sed -i SEDPARAM *.h
