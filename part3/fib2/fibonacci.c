#include "fibonacci.h"

typedef unsigned int uint;

char* fib_jono_mj(uint n) {
  uint m, i;
  uint fib1=1, fib2 = 0, curFib=0, kap=1, pit=0;
  char charFib[4];
 
  uint oldAlloc=1, newAlloc;

  char* ret = malloc(1*sizeof(char));
  newAlloc = 1*sizeof(char);
  /* printf("Old alloc %d, new alloc %d\n",oldAlloc,newAlloc); */
  
  for(i=0;i<n;i++) {
    if (i<2) {
      curFib = i;
      if(i==0) {
        kap = 2;
        ret = realloc(ret,kap*sizeof(char));
        oldAlloc = newAlloc;
        newAlloc = kap*sizeof(char);
        /* printf("2Old alloc %d, new alloc %d\n",oldAlloc,newAlloc); */
        sprintf(&ret[pit],"%d",curFib);
        pit++;
      } else {
        kap = 8;
        ret = realloc(ret,kap*sizeof(char));
        oldAlloc = newAlloc;
        newAlloc = 8*sizeof(char);
        /* printf("1Old alloc %d, new alloc %d\n",oldAlloc,newAlloc); */
        sprintf(&ret[pit],", %d",curFib);
        pit += 3;
      }
    } else {
      curFib = fib1 + fib2;
      sprintf(charFib,"%d",curFib);
      m = strlen(charFib)+3;
      if (pit+m > kap) {
        while(pit+m > kap) {
          kap *= 2;
        }
        ret = realloc(ret,kap*sizeof(char));
        oldAlloc = newAlloc;
        newAlloc = kap*sizeof(char);
        /* printf("3Old alloc %d, new alloc %d\n",oldAlloc,newAlloc); */
      } 
      sprintf(&ret[pit],", %d", curFib);

      fib2=fib1;
      fib1=curFib;
      pit += strlen(charFib)+2;
    }
}
  pit++;
  ret = realloc(ret,pit);
  return ret;
}
