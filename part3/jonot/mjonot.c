#include "mjonot.h"

char ** kopioi_mjt(char **mjt,size_t lkm) {
  int i,j;
  char** ret = (char**) malloc(lkm*sizeof(char *));
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

  return ret;
}
