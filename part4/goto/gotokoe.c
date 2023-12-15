#include "gotokoe.h"
#include <stdio.h>

int max2D(int **t2d, int height, int width) {
  int i=0;
  int j=-1;
  int curMax=0;

  goto newLoop;
newLoop:
  j++;
  if(j>width-1) goto rowOver;
  if(t2d[i][j] > curMax) goto newMax;
  goto newLoop;
rowOver:
  i++;
  j=-1;
  if(i>height-1) goto end;
  goto newLoop;
newMax:
  curMax=t2d[i][j];
  goto newLoop;
end:
  return curMax;
}

