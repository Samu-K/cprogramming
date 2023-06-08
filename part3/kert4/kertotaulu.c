#include "kertotaulu.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int countDigits(unsigned int num) { return num == 0 ? 1 : (int)(log10(num) + 1); }

char** luo_kertotaulu_mjt(uint a, uint b, uint c, uint d) {
  uint i,j, colLen, row=0,pos=0;
  uint rows=d-c+2;
  uint cols=b-a+2;
  uint maxDig = countDigits(b*d);
  uint rowLen = countDigits(d)+((maxDig+1)*cols);
  char** ret = malloc(sizeof(char)*rowLen*rows);
  char* rowString = malloc(sizeof(char)*rowLen);
 
  sprintf(rowString, "%*s",countDigits(d), " ");
  pos += countDigits(d);
  for(i=1;i<cols;i++) {
    colLen = countDigits(a*d);
    sprintf(&rowString[pos]," %*d", colLen ,a);
    pos += colLen+1;
    a++;
  }
  ret[row] = malloc(sizeof(char)*rowLen);
  ret[row] = rowString;
  row++;
  a -= cols-1;

  for(i=1;i<rows;i++) {
    ret[row] = malloc(sizeof(char)*rowLen);
    rowString = malloc(sizeof(char)*rowLen);
    pos = 0;
    sprintf(rowString, "%d",c);
    pos += countDigits(c);
    for(j=1;j<cols;j++) {
      uint num = a*c;
      colLen = countDigits(a*d);
      sprintf(&rowString[pos], " %*d",colLen, num);
      pos += colLen+1;
      a++;
    }
    ret[row] = rowString;
    a -= cols-1;
    row++;
    c++;
  }

  return ret;
}
