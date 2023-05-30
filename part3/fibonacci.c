#include "fibonacci.h"
#include <limits.h>
#include <stdlib.h>


unsigned int *fib_jono(unsigned int n) {
  unsigned int i;
  int sum=0;
  unsigned int* fib= malloc( sizeof(int) * n);
  fib[0]=0;
  fib[1]=1;
  
  if (!fib) {
    return NULL;
  }

  for(i=2;i<n;i++) {
    sum = 0;
    sum += fib[i-1];
    sum += fib[i-2];
    
    fib[i] = sum;
    
  }
  return fib;
}
