#include <stdio.h>

int main( int argc, char** argv )
{
   char* input = "abcdefghijklmnopqrstuvxyz\x08\x04\x8d\x20\n";
   printf( "%s", input );
}
