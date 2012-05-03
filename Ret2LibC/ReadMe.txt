Walkthrough: 


The File retlib.c is the vulnerable program. 

This was run using Fedora Core 4

First, from root run the first 3 lines in the "things to turn off"
then chmod 4755 retlib after compiling using the compile code in the file. 

from a normal user, follow the libC directions in the website. (Note: This may only be possible by running:
gdb retlib
r

Get a Stack!