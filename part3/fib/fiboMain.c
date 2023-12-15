#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i;
  unsigned int* fib = fib_jono(15);

  if (fib) {
    for (i=0;i<15;i++) {
      printf("%d\n",fib[i]);
    }
    free(fib);
  }

  return 0;
}
