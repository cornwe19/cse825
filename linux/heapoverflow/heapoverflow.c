#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  static char filename[] = "/tmp/heap-overflow.txt";
  static char buffer[64] = "";

  gets(buffer);

  FILE *fd = fopen(filename, "a");
  if (fd != NULL) {
      fputs(buffer, fd);
      fclose(fd);
  }

  return 0;
}
