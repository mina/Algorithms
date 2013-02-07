#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

#define M 9
#define N 10

typedef enum {COPY = 0, REPLACE = 1, INSERT = 2, DELETE = 3, TWIDDLE = 4, KILL = 5} move_t;

char y[] = "altruistic";
char x[] = "algorithm";

int k[6] = {50, 100, 200, 50, 100, 1};

int move[M + 1][N + 1];
int e[M + 1][N + 1];

void print_array(int array[M+1][N+1]) {
  for (int i = 0; i <= M; i++) {
    for (int j = 0; j <= N; j++) {
      printf("%3d, ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void get_edit_distance() {
  for (int i = M; i >= 0; i--) {
    e[i][N] = k[KILL];
    move[i][N] = KILL;
  }
  for (int j = N - 1; j >= 0; j--) {
    e[M][j] = e[M][j+1] + k[INSERT];
    move[M][j] = INSERT;
  }
  for (int i = M - 1; i >= 0; i--) {
    for (int j = N - 1; j >= 0; j--) {
      int result = INT_MAX;
      if (x[i] == y[j]) {
        int copy = k[COPY] + e[i+1][j+1];
        if (copy < result) {
          result = copy;
          e[i][j] = result;
          move[i][j] = COPY;
        }
      }
      if (x[i] == y[j+1] && x[i+1] == y[j] && i <= M - 2 && j <= N - 2) {
        int twiddle = k[TWIDDLE] + e[i+2][j+2];
        if (twiddle < result) {
          result = twiddle;
          e[i][j] = result;
          move[i][j] = TWIDDLE;
        }
      }
      int replace = k[REPLACE] + e[i+1][j+1];
      if (replace < result) {
        result = replace;
        e[i][j] = result;
        move[i][j] = REPLACE;
      }
      int insert = k[INSERT] + e[i][j+1];
      if (insert < result) {
        result = insert ;
        e[i][j] = result;
        move[i][j] = INSERT;
      }

      int delete = k[DELETE] + e[i+1][j];
      if (delete < result) {
        result = delete;
        e[i][j] = result;
        move[i][j] = DELETE;
      }
    }
  }
}

void print_min_distance() {
  int i = 0, j = 0;
  while (j <= N && move[i][j] != KILL) {
    switch (move[i][j]) {
      case COPY:
        printf("copy %c at %d and %d\n", x[i], i,j);
        i++;
        j++;
        break;
      case REPLACE:
        printf("replace %c at %d and %d\n", y[j], i, j);
        i++;
        j++;
        break;
      case INSERT:
        printf("insert %c at %d and %d\n", y[j], i, j);
        j++;
        break;
      case DELETE:
        printf("delete %c at %d and %d\n", x[i], i, j);
        i++;
        break;
      case TWIDDLE:
        printf("twiddle %c and %c at %d and %d\n", x[i], x[i+1], i, j);
        i = i + 2;
        j = j + 2;
        break;
    }
  }
}

int main () {
  get_edit_distance();
  print_array(e);
  print_array(move);
  print_min_distance();
}
