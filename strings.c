#include <stdlib.h>
#include <stdio.h>
#include "mina.h"
#include <string.h>

char *get_string() {
  char *str = malloc(sizeof(char) * 13);
  str = "this\n";
  return str;
}

int main() {
  char *str = malloc(sizeof(char) * 6);
  strcpy(str, "thiss\n");
  for (int i = 0; i <= 15; i++) {
    printf("%c,", str[i]);
  }
}
