#include "vaihto.h"

void vaihda(int* a, int* b) {
  int temp = *b;

  *b = *a;
  *a = temp;
}

void jarjesta(int * a,int* b, int* c) {
  if (*a > *b) {
    vaihda(a,b);
  }

  if (*b > *c) {
    vaihda(b,c);
  }

  if (*a > *b) {
    vaihda(a,b);
  }
}
