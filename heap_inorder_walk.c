#include <stdio.h>

#define HEAP_SIZE 10

inline int parent (int i) {
  return (i - 1)/2;
}

inline int left(int i) {
  return 2 * i + 1;
}

int right (int i) {
  return 2 * i + 2;
}

void maxHeapInOrderTreeWalk(int *heap) {
}

int main (int argc, char *argv) {
  int heap[HEAP_SIZE] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
  maxHeapInOrderTreeWalk(heap);
}
