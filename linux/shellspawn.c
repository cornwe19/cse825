#include <unistd.h>
#include <stdio.h>

char* function()
{
   char input[10];
   printf( "Enter password: " );
   gets( input );

   return input;
}

int main()
{
   char* name[2];

   name[0] = "/bin/sh";
   name[1] = NULL;

   char* input = function();
   if( strcmp(input,"shell") == 0 )
   {
      printf( "Password accepted, launching shell." );
      execve(name[0], name, NULL);
   }

   return 0;
}
