#include "tulostus.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

void tulostaDblTaulu(double *array, size_t n, const char *arrayName, int prec, const char *fileName) {
  size_t i=0;
  FILE *fptr;

  fptr = fopen(fileName,"w");
  
  for(i=0;i<n;i++) {
    fprintf(fptr,"%s[%ld] = %.*lf\n",arrayName,i,prec,array[i]);
  }

  fclose(fptr);
}
