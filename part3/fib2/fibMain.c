#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

int main(void) {
  char* fib = fib_jono_mj(15);
  printf("%s\n",fib);
  return EXIT_SUCCESS;
}
