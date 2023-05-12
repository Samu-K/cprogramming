#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#include "bitit.h"

unsigned long long int createMask(int bitLen) {
  unsigned long long int mask = 1;
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
  printf("%c\n",x);

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
  printf("Number of 0 bits: %d\n", zeroCount);
  printf("Number of 1 bits: %d\n", oneCount);
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
  printf("Number of 0 bits: %d\n", zeroCount);
  printf("Number of 1 bits: %d\n", oneCount);
}

void intBitit(int x) {
  int bitLen = 32;
  unsigned long long int mask = createMask(bitLen);
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
  printf("Number of 0 bits: %d\n", zeroCount);
  printf("Number of 1 bits: %d\n", oneCount);
}

void longBitit(long int x) {
  int bitLen = 64;
  long int mask = createMask(bitLen);
  int i = 0;
  int zeroCount = 0;
  int oneCount = 0;

  /* print actual value */ 
  printf("%ld\n",x);

  /* print bit value */ 
  for (i = 0; i <= bitLen - 1; i++) {
    if ( x & mask) {
      printf("1");
      oneCount++;
    } else {
      printf("0");
      zeroCount++;
    }
    mask = mask >> 1;
    mask |= (1LL << (bitLen - 1));
  }
  printf("\n");
  printf("Number of 0 bits: %d\n", zeroCount);
  printf("Number of 1 bits: %d\n", oneCount);

}

