#include "kertotaulu.h"
#include <stdlib.h>
#include <stdio.h>

Kertotaulu* luoKertotaulu(uint a, uint b, uint c, uint d) {
  int i,j;
  int rows=d-c+2;
  int cols=b-a+2;
  
  Kertotaulu* ret = malloc(sizeof(Kertotaulu));
  uint** kert = malloc(sizeof(uint*)*rows);

  if (!ret) {
    return NULL;
  }

  ret->a=a;
  ret->b=b;
  ret->c=c;
  ret->d=d;

  kert[0] = malloc(sizeof(uint)*(cols)); 
  kert[0][0] = 1;

  for(j=1;j<cols;j++) {
    kert[0][j] = a;
    a++;
  }
  a = ret->a;

  for(i=1;i<rows;i++) {
    kert[i] = malloc(sizeof(uint)*(cols));
    for(j=0;j<cols;j++) {
      kert[i][j] = c*kert[0][j];
    }
    c++;
  };

  ret->kertotaulu = kert;

  return ret;
}

void tuhoaKertotaulu(Kertotaulu* kt) {
  uint i;
  uint rows = kt->d - kt->c + 2;
  if (kt == NULL) {
      return;  
  }

  for (i = 0; i < rows; i++) {
      free(kt->kertotaulu[i]);
  }
  free(kt->kertotaulu);

  free(kt);
}
