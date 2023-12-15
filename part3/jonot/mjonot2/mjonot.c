#include "mjonot.h"
#include <stdio.h>

char ** jarjesta_mjt(char **mjt,size_t lkm,int (*vrt)(const char*, const char*)) {
  int i=0;
  int j=0;
  int sortFlag=1;
  char** ret = (char**) malloc(lkm*sizeof(char *));
  size_t len1,len2;
  int sorted=0;
  char* val1,*val2,*t;
  int cmp;

  if (!ret) {
    return NULL;
  }

  for(i = 0; i < lkm; i++) {
    size_t len = strlen(mjt[i]);
    char* toCopy = (char*)malloc((len+1) * sizeof(char));
    if (!toCopy) {
      for (j=0;j < i; j++) {
        free(ret[j]);
      }
      free(ret);
      return NULL;
    }
    strcpy(toCopy,mjt[i]);

    ret[i] = toCopy;
  }

  /*
   * Idea:
   *    Compare 1. and 2. value
   *        if 2. is more than 1., then swap
   *        Now move to next value and repeat
   */
  while(sortFlag) {
    sorted=0;
    for(i = 0; i < lkm-1; i++) {
      len1 = strlen(ret[i]);
      len2 = strlen(ret[i+1]);
      val1 = (char*) malloc((len1+1)*sizeof(char));
      val2 = (char*) malloc((len2+1)*sizeof(char));
      strcpy(val1,ret[i]);
      strcpy(val2,ret[i+1]);

      cmp = (*vrt)(val1,val2);
      if(cmp == 0) {
        t = ret[i];
        ret[i] = ret[i+1];
        ret[i+1] = t;
        sorted=1;
      }
    }
    if(!sorted) {
      sortFlag = 0;
    }
  }
  free(val1);
  free(val2);
  

  return ret;
}
