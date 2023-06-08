#include "kertotaulu.h"

int countDigits(unsigned int num) { return num == 0 ? 1 : (int)(log10(num) + 1); }

char** luo_kertotaulu_mjt(uint a, uint b, uint c, uint d) {
  uint i,j;
  uint rows=d-c+2;
  uint cols=b-a+2;
  uint rowNum=a,colNum=c;
  uint maxDig = countDigits(b*d);
 
  printf("%*s",maxDig," ");
  for(i=1;i<cols;i++) {
    printf(" %*d",maxDig,a);
    a++;
  }
  printf("\n");
  a -= cols;

  for(i=1;i<rows;i++) {
    printf("%*d ",maxDig,colNum);
    for(j=1;j<cols;j++) {
      uint num = rowNum*colNum;
      printf("%*d ",maxDig,num);
      rowNum++;
    }
    printf("\n");
    rowNum=a;
    colNum++;
  }
}
