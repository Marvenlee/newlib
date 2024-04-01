# Newlib port to CheviotOS

This repository is a fork of the Sourceware Newlib repository at
https://sourceware.org/git/newlib-cygwin.git.

The official Newlib website is at: [https://sourceware.org/newlib/](https://sourceware.org/newlib/)

The branch "cheviot-main" contains changes to build Newlib on CheviotOS
and is branched from the 4.1.0 release of Newlib.

CheviotOS is designed to be built on arm targets with an arm-none-eabi-gcc
cross-compiler toolchain. As such, the CheviotOS specific changes are
mostly confined to the newlib/libc/sys/arm directory.

The changes include library code to interface Newlib to the CheviotOS
system calls and a number of BSD library sources that were required to build
BSD utilities such as "login" that depend on Berkeley DB sources.
These were placed in here to avoid having to specify additional link libraries
on the command line when building projects.

The BSD sources will be moved into a separate folder to separate these
from the CheviotOS specific sources.


# Important files

Some important files for future reference:

   * newlib/libc/sys/arm/syscall.S - System calls
   * newlib/libc/sys/arm/sys/syscalls.h - Header file for system calls
   * newlib/libc/sys/arm/sys/fsreq.h - Filesystem handler and device driver messages


