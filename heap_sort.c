#include <stdio.h>

void print_array(int *array, int size) {
  for (int i = 0; i <= size -1; i++) {
    printf("%d, ", array[i]);
  }
  printf("\n");
}

int parent(int i) {
  return (i - 1) / 2;
}

int left_child(int i) {
  return 2 * i + 1;
}

int right_child(int i) {
  return 2 * i + 2;
}

void max_heapify(int *array, int size, int index) {
  if (index > size / 2 - 1) {
    return;
  }
  int largest;
  if (array[index] >= array[left_child(index)]) {
    largest = index;
  } else {
    largest = left_child(index);
  }
  if (right_child(index) <= (size - 1) &&
      array[right_child(index)] > array[largest] ) {
    largest = right_child(index);
  }
  if (largest != index) {
    int temp;
    temp = array[largest];
    array[largest] = array[index];
    array[index] = temp;
    max_heapify(array, size, largest);
  }
}

void build_max_heap(int *array, int size) {
  int i;
  for (i = size / 2 - 1; i >= 0; i--) {
    max_heapify(array, size, i);
  }
}

void heap_sort (int *array, int size) {
  int temp, heap_size = size;
  build_max_heap(array, heap_size);
  for (int i = 0; i <= size - 1; i++) {
    temp = array[heap_size - 1];
    array[heap_size - 1] = array[0];
    array[0] = temp;
    heap_size--;
    max_heapify(array, heap_size, 0);
  }
}



int main() {
  int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
  heap_sort(array, 10);
  print_array(array, 10);
}
