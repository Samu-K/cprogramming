#include "muunna.h"
#include <stdio.h>

void muunnaTaulu(unsigned int l, double *taulu, double (*f)(double)) {
  unsigned int i = 0;

  for (i = 0; i < l; i++) {
      taulu[i] = f(taulu[i]);
  }
}
