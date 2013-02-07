#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define SIZE 10

void print_array(int *array, int size) {
  assert(array != NULL && size >= 0);
  for (int i = 0; i < size; i++) {
    printf ("%d, ", array[i]);
  }
  printf("\n");
}

void my_bubble_sort(int *array, int size) {
  assert(array != NULL && size >= 0);
  for (int i = 0; i <= size - 1; i++) {
    // bubble down the ith smallest item to the ith slot
    for (int j = size - 1; j >= i + 1; j--) {
      if (array[j - 1] > array[j]) {
        int temp = array[j];
        array[j] = array[j - 1];
        array[j - 1] = temp;
      }
    }
  }
}

void my_insertion_sort(int *array, int size) {
  assert(array != NULL && size >= 0);
  for (int i = 1; i <= size - 1; i++) {
    int value = array[i], j = i - 1;
    // insert value into sorted sequence 0...i-1
    while (j >= 0 && array[j] > value) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = value;
  }
}

void my_quicksort (int *array, int size) {
  if (size <= 1) {
    return;
  }

  // pick an r to partition around at random
  int r = rand() % size, temp;

  // put that array[r] at the end of the array
  temp = array[r];
  array[r] = array[size - 1];
  array[size - 1] = temp;

  // partion the array around r. sequence 0..i is <= r. sequence i+1 to j-1 is < r.
  int i = -1;
  for (int j = 0; j <= size - 2; j++) {
    if (array[j] <= array[size - 1]) {
      i++;
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }

  // return array[r] to it's proper position
  temp = array[i + 1];
  array[i + 1] = array[size - 1];
  array[size - 1] = temp;

  // recurse on the 2 halves of the array remaining
  my_quicksort(array, i + 1);
  my_quicksort(array + i + 2, size - i - 2);
}

// heapsort helpers {{
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

// }}

void my_heap_sort (int *array, int size) {
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

void my_merge_sort (int *array, int n) {
  if (array == NULL) {
    fprintf(stderr, "error sorting null array\n");
  }
  if (n <= 1) {
    return;
  }
  int mid = n / 2;
  my_merge_sort(array, mid);
  my_merge_sort(array + mid, n - mid);
  int L[mid], R[n-mid];
  for (int i = 0; i <= mid - 1; i++) {
    L[i] = array[i];
  }
  for (int i = 0; i <= n - mid - 1; i++) {
    R[i] = array[i + mid];
  }
  int i = 0, j = 0, k = 0;
  while (i <= mid - 1 && j <= n - mid - 1) {
    if (L[i] < R[j]) {
      array[k] = L[i];
      i++;
    }
    else {
      array[k] = R[j];
      j++;
    }
    k++;
  }
  while (i <= mid - 1) {
    array[k] = L[i];
    i++;
    k++;
  }
  while (j <= n - mid - 1) {
    array[k] = R[j];
    j++;
    k++;
  }
}


int main() {
  int array[SIZE] = { 1, 5, 9, 7 ,8, 0, 2, 9, 3, 6 };
  my_bubble_sort(array, SIZE);
  print_array(array, SIZE);

  int array2[SIZE] = { 1, 5, 9, 7 ,8, 0, 2, 9, 3, 6 };
  my_insertion_sort(array2, SIZE);
  print_array(array2, SIZE);

  int array3[SIZE] = { 1, 5, 9, 7 ,8, 0, 2, 9, 3, 6 };
  my_quicksort(array3, SIZE);
  print_array(array3, SIZE);

  int array4[SIZE] = { 1, 5, 9, 7 ,8, 0, 2, 9, 3, 6 };
  my_heap_sort(array4, SIZE);
  print_array(array4, SIZE);

  int array5[SIZE] = { 1, 5, 9, 7 ,8, 0, 2, 9, 3, 6 };
  my_merge_sort(array5, SIZE);
  print_array(array5, SIZE);

  return 0;
}
