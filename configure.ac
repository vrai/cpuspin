# Copyright (c) 2013, Vrai Stacey.
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
# 02110-1301, USA.

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

