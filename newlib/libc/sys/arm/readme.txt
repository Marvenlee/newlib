
When adding files to this directory, add the name
of the object file to makefile.am then run the following
commands in this directory.


aclocal -I ../../..
autoconf
automake --cygnus --add-missing Makefile
