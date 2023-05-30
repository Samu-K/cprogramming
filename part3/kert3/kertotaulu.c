#include "kertotaulu.h"
#include <stdlib.h>
#include <stdio.h>

Kertotaulu* luoKertotaulu(uint a, uint b, uint c, uint d) {
  int i,j;
  int start = c;

  Kertotaulu* ret = malloc(sizeof* ret);
  int rows=d-c+2;
  int cols=b-a+2;
  int size= rows*cols;

  uint** kert = malloc(sizeof(unsigned int*)*size);

  ret->a=a;
  ret->b=b;
  ret->c=c;
  ret->d=d;

  for(i=0;i<=rows;i++) {
    kert[i] = malloc(sizeof(uint)*cols);
    for(j=0;j<=cols;j++) {
      kert[i][j] = a;
      c++;
    }
    a++;
    c=start;
  };

  ret->kertotaulu = kert;

  return ret;
}
