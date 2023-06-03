#include "fibonacci.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* fib_jono_mj(uint n) {
  uint i,j,curFib,fib1,fib2,usedSpace;

  char* fibString = malloc(6*sizeof(char));  
  sprintf(fibString,"0, 1");
  fib1 = 1;
  fib2 = 0;

  usedSpace=6;
  for(i=2;i<n;i++) {
    curFib = fib1 + fib2;
    fibString = realloc(fibString,sizeof(fibString)+sizeof(curFib)+3*sizeof(char));
    sprintf(fibString,"%s, %d",fibString, curFib);
    
    fib2 = fib1;
    fib1 = curFib;
  }
  fibString = realloc(fibString, sizeof(fibString)+1);
  fibString[strlen(fibString)] = '/0';

  return fibString;
}
