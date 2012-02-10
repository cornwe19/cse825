#include <stdio.h>

void function( int a, int b, int c )
{
   char buffer1[5];
   char buffer2[10];
   unsigned *ret;

   ret = buffer1 + 13; 
   (*ret) += 8;
}

int main ( int argc, char** argv )
{
   int x;

   x = 0;
   function( 1, 2, 3 );
   x = 1;
   printf( "%d\n", x );
}

