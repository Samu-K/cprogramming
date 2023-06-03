#include "fibonacci.h"

char* fib_jono_mj(uint n) {
  uint kap, pit,m, i, j;
  uint fib1=1, fib2 = 0, curFib=0;

  char* ret = malloc(sizeof(char));

  kap = 1;
  pit = 0;

  printf("0 ");
  printf("1 ");

  for(i=0;i<n;i++) {
    if (i<0) {
      curFib = i;
      if(pit+m <= kap) {
        sprintf(ret, "%s, %d",ret, curFib);
      }
    }
    curFib = fib1 + fib2;
    printf("%d ", curFib);
    fib2=fib1;
    fib1=curFib;
  }

  printf("\n");
}
