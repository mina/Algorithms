#include "mina.h"
#include <stdlib.h>
#include <stdio.h>

int unique(char *str) {
  int buf[256] = {0};
  while (*str != '\0') {
    if (buf[*str] == 1) {
      print_array(buf, 256);
      return 0;
    }
    buf[*str] = 1;
    str++;
  }
  return 1;
}

int main() {
  char str[] = "no repeats";
  if (unique(str)) {
    printf("the string is unique\n");
  }
  else {
    printf("the sting is NOT unique\n");
  }
}
