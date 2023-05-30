#include <stdio.h> 
#include "muunna.h"

double triplaa(double x)
{
  return 3*x;
}

int main(void) {
  int i = 0;
  double dt[10] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0}; 
  muunnaTaulu(10, dt, triplaa);
  for(i = 0; i < 10; ++i)
  {
    printf(" %.1f", dt[i]);  /* Tulostus 1 desimaalin tarkkuudella. */
  }
  printf("\n");

  return 1;
}
