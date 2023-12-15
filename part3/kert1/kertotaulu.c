#include "kertotaulu.h"

Kertotaulu* luoKertotaulu(uint a, uint b, uint c,uint d) {
  uint i,j;
  Kertotaulu* ret = Kertotaulu();
  int rowNum=a;
  int colNum=c;

  uint rows = (d-c+2);
  uint cols = (b-a+2);
  uint size = rows*cols;
  
  uint** kert = malloc(size*sizeof(uint*));
  
  for (i=0;i<rows;i++) {
    uint* row = malloc(cols*sizeof(uint));
    for (j=0;j<cols;i++) {
      row[j] = rowNum*colNum;
      rowNum++;
    }
    kert[i] = row;
    rowNum=a;
    colNum++;
  }

  ret->kertotaulu = kert;
  ret->a = a;
  ret->b = b;
  ret->c = c;
  ret->d = c;

  return ret;
}
