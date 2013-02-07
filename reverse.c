#include <stdlib.h>
#include <stdio.h>

void print_array(int array[], int n) {
  for (int i = 0; i <= n - 1; i++) {
    printf("%d, ", array[i]);
  }
}

void reverse(int array[], int n) {
  if (array == NULL) {
    fprintf(stderr, "error reversing null array");
  }
  int i = 0;
  int j = n - 1;
  while (i < j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    i++;
    j--;
  }
}

int main() {
  int array[] = {1, 2, 3, 4, 5, 6, 7};
  reverse(array, sizeof(array)/sizeof(int));
  print_array(array, sizeof(array)/sizeof(int));
}
