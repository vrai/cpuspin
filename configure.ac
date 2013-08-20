AC_PREREQ([2.59])

AC_INIT([cpuspin], [1.0.0], [vrai.stacey@gmail.com])
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADER(src/config.h)
AC_CONFIG_FILES([Makefile \
                 src/Makefile])
AM_INIT_AUTOMAKE

### Make sure we're in the right directory
AC_CONFIG_SRCDIR(./src/cpuspin.c)

### Make sure that the necessary programs are available
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LIBTOOL

### Warnings up to eleven
AX_CHECK_COMPILER_FLAGS(-Wall,CXXFLAGS+=" -Wall")

AC_OUTPUT

