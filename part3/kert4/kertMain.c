#include "kertotaulu.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  uint a = 1;
  uint b = 10;
  uint c = 1;
  uint d = 10;

  char** kertotaulu = luo_kertotaulu_mjt(a,b,c,d);
  uint i = 0;
  for(i = 0; i <= (d-c+1); ++i)    /* Rivit */
  {
    printf("%s\n", kertotaulu[i]);
    free(kertotaulu[i]);
  }
  free(kertotaulu);
  return 0;
}
