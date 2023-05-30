#include "kertotaulu.h"
#include <stdlib.h>
#include <stdio.h>

Kertotaulu* luoKertotaulu(uint a, uint b, uint c, uint d) {
  int i,j;

  Kertotaulu* ret = malloc(sizeof* ret);
  int rows=d-c+2;
  int cols=b-a+2;
  int size= rows*cols;

  uint** kert = malloc(sizeof(unsigned int*)*size);

  ret->a=a;
  ret->b=b;
  ret->c=c;
  ret->d=d;

  for(i=0;i<2;i++) {
    kert[i] = malloc(sizeof(uint)*cols);
    if (i==0) {
      kert[0][0] = 1;
    }

    for(j=1;j<=cols;j++) {
      kert[i][j] = a;
      a++;
    }
  }
  a = ret->a;

  for(i=1;i<=rows;i++) {
    kert[i] = malloc(sizeof(uint)*cols);
    for(j=0;j<=cols;j++) {
      kert[i][j] = c*kert[0][j];
    }
    c++;
  };

  ret->kertotaulu = kert;

  return ret;
}

void tuhoaKertotaulu(Kertotaulu* kt) {
  uint i;
  if (kt == NULL) {
      return;  
  }

  for (i = 0; i < kt->d - kt->c + 2; i++) {
      free(kt->kertotaulu[i]);
  }
  free(kt->kertotaulu);

  free(kt);
}
