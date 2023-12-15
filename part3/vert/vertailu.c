#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vertailu.h"
#include "rectangle.h"

int rectAlaVrt(const void *a, const void *b) {
  
  Rectangle* const *rec1 = a;
  Rectangle* const *rec2 = b;
  int r1w = (*rec1)->width;
  int r2w = (*rec2)->width;
  int r1h = (*rec1)->height;
  int r2h = (*rec2)->height;

  return r1w*r1h > r2w*r2h;
}

int rectXyVrt(const void *a, const void *b) {

  Rectangle* const* rec1 = a;
  Rectangle* const* rec2 = b;

  int r1x = (*rec1)->origin.x;
  int r1y = (*rec1)->origin.y;
  int r2x = (*rec2)->origin.x;
  int r2y = (*rec2)->origin.y;

  if (r1x > r2x) {
    return 1;
  } else if (r1x < r2x) {
    return -1;
  } else {
    return r1y > r2y;
  }

}

int rectLeveysVrt(const void *a, const void *b) {
  Rectangle* const* rec1 = a;
  Rectangle* const* rec2 = b;

  return (*rec1)->width < (*rec2)->width;
}

int mjPitAakkosVrt(const void *a, const void *b) {
  int i;
  char* const *str1 = a;
  char* const *str2 = b;

  if (strlen(*str1) < strlen(*str2)) {
    return 1;
  } else if (strlen(*str1) == strlen(*str2)) {
    for(i=0;i<strlen(*str1);i++) {
      if((*str1)[i] > (*str2)[i]) {
        return 1;
      } else if((*str1)[i] < (*str2)[i]) {
        return -1;
      }
    }
    return 0;
  } else {
    return -1;
  }
}


