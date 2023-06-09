#include "kertotaulu.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int countDigits(unsigned int num) { return num == 0 ? 1 : (int)(log10(num) + 1); }

char** luo_kertotaulu_mjt(uint a, uint b, uint c, uint d) {
  uint i,j, colLen, row=0,pos=0;
  uint curAlloc=0, totAlloc=0;
  uint rows=d-c+2;
  uint cols=b-a+2;
  uint maxDig = countDigits(b*d);
  uint rowLen = countDigits(d)+((maxDig)*cols)-1;
  char** ret = malloc(sizeof(char)*rowLen*rows);
  curAlloc = sizeof(char)*rowLen*rows;
  totAlloc += curAlloc;
  printf("Allocated %d, total %d\n",curAlloc,totAlloc);
  ret[row] = malloc(sizeof(char)*rowLen);
  curAlloc = sizeof(char)*rowLen;
  totAlloc += curAlloc;
  printf("Allocated %d, total %d\n",curAlloc,totAlloc);

  sprintf(&ret[row][pos], "%*s",countDigits(d), " ");
  pos += countDigits(d);
  for(i=1;i<cols;i++) {
    colLen = countDigits(a*d);
    sprintf(&ret[row][pos]," %*d", colLen ,a);
    pos += colLen+1;
    a++;
  }

  row++;
  a -= cols-1;

  for(i=1;i<rows;i++) {
    ret[row] = malloc(sizeof(char)*rowLen);
    curAlloc = sizeof(char)*rowLen;
    totAlloc += curAlloc;
    printf("Allocated %d, total %d\n",curAlloc,totAlloc);
    pos = 0;
    sprintf(&ret[row][pos], "%d",c);
    pos += countDigits(c);
    for(j=1;j<cols;j++) {
      uint num = a*c;
      colLen = countDigits(a*d);
      sprintf(&ret[row][pos], " %*d",colLen, num);
      pos += colLen+1;
      a++;
    }
    a -= cols-1;
    row++;
    c++;
  }

  return ret;
}
