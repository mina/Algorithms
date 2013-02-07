#include <stdio.h>

void print_array(char array[], int n) {
  printf("%s, ", array);
  for (int i = 0; i <= n - 1; i++) {
    printf("%c, ", array[i]);
  }
}
