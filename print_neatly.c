#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

#define SIZE 200
#define M 80

int space[SIZE];
int newline[SIZE];
const char *words[SIZE] = {
  "This" , "is" , "a" , "very" , "sexy" , "paragraph" , "and" , "it" , "is"
    , "going" , "to" , "be" , "printed" , "neatly" , "using" , "like" , "the"
    , "best" , "algorithm" , "in" , "the" , "world." , "As" , "long" , "as"
    , "the" , "algorithm" , "actually" , "works" , "you" , "know." , "If" , "not"
    , "then" , "it" , "is" , "crappy" , "and" , "I" , "will" , "just" , "cry."
    , "The", "Nokia", "Lumia", "920", "is", "the", "company’s", "third", "attempt",
  "at", "launching", "the", "definitive", "Windows", "Phone.", "In", "April", "Nokia",
  "and", "Microsoft", "tried", "to", "convince", "the", "world", "that", "the",
  "Lumia", "900", "and", "Windows", "Phone", "7.5", "was", "that", "device", "but",
  "that", "claim", "had", "a", "shorter", "expiration", "date", "than", "anybody",
  "realized.", "Its", "days", "were", "numbered", "as", "Windows", "Phone",
  "8", "was", "an", "under-the-hood", "overhaul", "that", "wasn’t", "compatible",
  "with", "the", "phone." , "The", "Lumia", "920’s", "launch", "was",
  "mishandled", "at", "best.", "The", "compelling", "PureView", "camera",
  "was", "undercut", "by", "a", "marketing", "snafu", "when", "Nokia",
  "faked", "a", "video", "purporting", "to", "show", "its", "low-light",
  "capabilities.", "Neither", "Nokia", "nor", "its", "carrier", "partners",
  "could", "commit", "to", "a", "firm", "release", "date", "and", "potential",
  "buyers", "have", "had", "to", "wait", "nearly", "two", "months", "to",
  "purchase", "the", "phone.", "In", "that", "time", "both", "the", "iPhone",
  "5", "and", "the", "Nexus", "4", "appeared", "on", "the", "scene", "—",
  "the", "competition", "has", "not", "stood", "still", "Though", "the",
  "Lumia", "920", "stumbled", "out", "of", "the", "it", "still", "aims", "to",
  "be", "the", "this" };


void print_array(int *array) {
  for (int i = 0; i <= SIZE - 1; i++) {
    printf("%d, ", array[i]);
  }
  printf("\n");
}

int extra_spaces(int i, int j, const char **words) {
  assert(i <= j);
  int result = M - j + i;
  for (int k = i; k <= j; k++) {
    result -= strlen(words[k]);
  }
  return result;
}

int *find_neat_print(const char **words) {
  for (int i = SIZE - 1; i >= 0; i--) {
    if (extra_spaces(i, SIZE - 1, words) >= 0) {
      space[i] = 0;
      newline[i] = SIZE - 1;
    }
    else {
      int j = i;
      space[i] = INT_MAX;
      while ( extra_spaces(i, j, words) >= 0 && j <= SIZE - 1 ) {
        int result = pow( extra_spaces(i, j, words) * 1.0, 3.0 );
        if (result < space[i] ) {
          space[i] = result;
          newline[i] = j;
        }
        j++;
      }
    }
  }
  return newline;
}

void print_paragraph(const char **words, int *newline) {
  int word_index = 0;
  while (word_index <= SIZE - 1) {
    int newline_after = newline[word_index];
    for (; word_index <= newline_after; word_index++) {
      printf("%s ", words[word_index]);
    }
    printf("\n");
  }
}

int main() {
  int *newline = find_neat_print(words);
  print_paragraph(words, newline);
}
