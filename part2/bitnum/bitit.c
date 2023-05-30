#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#include "bitit.h"

long int createMask(int bitLen) {
  long int mask = 1;
  mask = mask << (bitLen - 1);
  return mask;
}

void scharBitit(signed char x) {
  int bitLen = CHAR_BIT;
  int mask = createMask(bitLen);
  int i = 0;
  int zeroCount = 0;
  int oneCount = 0;

  /* Print the actual value */ 
  printf("%d\n",x);

  /* Print the bit value */ 
  for (i = 0; i <= bitLen - 1; i++) {
    if ( x & mask) {
      printf("1");
      oneCount++;
    } else {
      printf("0");
      zeroCount++;
    }
    mask >>= 1;
  }
  printf("\n");
  printf("%d\n", zeroCount);
  printf("%d\n", oneCount);
}

void shortBitit(short int x) {
  int bitLen = 16;
  int mask = createMask(bitLen);
  int i = 0;
  int zeroCount = 0;
  int oneCount = 0;

  /* print actual value */ 
  printf("%d\n",x);

  /* print bit value */ 
  for (i = 0; i <= bitLen - 1; i++) {
    if ( x & mask) {
      printf("1");
      oneCount++;
    } else {
      printf("0");
      zeroCount++;
    }
    mask >>= 1;
  }
  printf("\n");
  printf("%d\n", zeroCount);
  printf("%d\n", oneCount);
}

void intBitit(int x) {
  int bitLen = 32;
  long int mask = createMask(bitLen);
  int i = 0;
  int zeroCount = 0;
  int oneCount = 0;

  /* print actual value */ 
  printf("%d\n",x);

  /* print bit value */ 
  for (i = 0; i <= bitLen - 1; i++) {
    if ( x & mask) {
      printf("1");
      oneCount++;
    } else {
      printf("0");
      zeroCount++;
    }
    mask >>= 1;
  }
  printf("\n");
  printf("%d\n", zeroCount);
  printf("%d\n", oneCount);
}

void longBitit(long int x) {
  int i = 0;
  int zeroCount = 0;
  int oneCount = 0;

  /* print actual value */ 
  printf("%ld\n",x);

  /* print bit value */ 
  for (i = sizeof(long int)*CHAR_BIT-1; i >= 0; i--) {
    printf("%ld", (x >> i) & 1);
    if (((x >> i) & 1) == 0) {
        zeroCount++;
    } else {
        oneCount++;
    }
  }
  printf("\n");
  printf("%d\n", zeroCount);
  printf("%d\n", oneCount);

}

