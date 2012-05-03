/* retlib.c */
/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int bof(FILE *badfile)
{
char buffer[12];
	fread(buffer, sizeof(char), badfile);
	return 1;
}
int main(int argc, char **argv)
{
	FILE *badfile;
	badfile = fopen("badfile", "r");
	bof(badfile);
	printf("Returned Properly\n");
	fclose(badfile);
	return 1;
}

//gcc -g --static -Wa,--execstack -o retlib retlib.c