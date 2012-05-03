/* exploit_1.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(){
char* shell = getenv("MYSHELL");
if (shell)
printf("%x\n", (unsigned int)shell);
}
