#include <stdio.h>

const char shellcode[] = "\x8d\x45\xea\x83\xc0\x1a\x89\x45\xf4\x8b\x45\xf4\x8b\x00\x8d\x50\x32\x8b\x45\xf4\x89\x10\x8d\x45\xea\xc9\xc3\xbf\xff\xf2\xf1";
                   
int main( int argc, char** argv )
{
   printf( shellcode );
}
