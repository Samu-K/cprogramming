#include "genhaku.h"
#include <stdlib.h>
#include <stdio.h>

size_t etsi(void* search, size_t searchSize, void *find,size_t findSize, size_t byteSize) {
  size_t i = 0;
  size_t j=0;
  int k=0;
  int matchFlag=1;
  int matchFound=0;
  int findPos=0;
  size_t matchCount=0;

  typedef unsigned char uchar;

  uchar* searchPtr = (uchar*)search;
  uchar* findPtr = (uchar*)find;
  uchar findByte = findPtr[k*byteSize];

  for (i = 0; i < searchSize; i++) {
    if (matchFound) {
      break;
    }
    /* printf("Element %zu:\n", i); */
    for (j = 0; j < byteSize; j++) {
      uchar searchByte = searchPtr[i*byteSize+j];
      /* printf("S:%02X\nF:%02X\n\n",searchByte,findByte); */
      if(searchByte != findByte) {
        matchFlag=0;
        k=0;
        matchCount=0;
        findByte = findPtr[k*byteSize];
        break;
      } else {
        findByte = findPtr[k*byteSize+j+1];
      }
    }

    if(matchFlag) {
      /* printf("Match at %ld\n",i); */
      matchCount++;
      k++;
      findByte = findPtr[k*byteSize];
    }
    matchFlag=1;
    
    if(matchCount == findSize) {
      /* printf("full match, from %ld to %ld", */
      /*         i-findSize+1,i); */
      findPos=i-findSize+1;
      matchFound=1;
    }
    /* printf("\n"); */
  }
  
  return matchFound ? findPos : searchSize;
}
