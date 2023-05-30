#include "bitit.h"
#include <limits.h>

void kaannaScharBitit(signed char *x) {
    unsigned int i, j;
    signed char tmp = *x;

    for (i = 0, j = CHAT_BIT-1; i < j; ++i, --j) {
        signed char bit_i = (tmp >> i) & 1;
        signed char bit_j = (tmp >> j) & 1;

        if (bit_i != bit_j) {
            tmp ^= (1 << i);
            tmp ^= (1 << j);
        }
    }

    *x = tmp;
}

void kaannaShortBitit(short *x) {
    unsigned int i, j;
    short tmp = *x;

    for (i = 0, j = 2*CHAR_BIT-1; i < j; ++i, --j) {
        short bit_i = (tmp >> i) & 1;
        short bit_j = (tmp >> j) & 1;

        if (bit_i != bit_j) {
            tmp ^= (1 << i);
            tmp ^= (1 << j);
        }
    }

    *x = tmp;
}

void kaannaIntBitit(int *x) {
    unsigned int i, j;
    int tmp = *x;

    for (i = 0, j = 4*CHAR_BIT-1; i < j; ++i, --j) {
        int bit_i = (tmp >> i) & 1;
        int bit_j = (tmp >> j) & 1;

        if (bit_i != bit_j) {
            tmp ^= (1 << i);
            tmp ^= (1 << j);
        }
    }

    *x = tmp;
}

void kaannaLongBitit(long *x) {
    unsigned int i, j;
    long tmp = *x;

    for (i = 0, j = 8*CHAR_BIT-1; i < j; ++i, --j) {
        long bit_i = (tmp >> i) & 1;
        long bit_j = (tmp >> j) & 1;

        if (bit_i != bit_j) {
            tmp ^= (1L << i);
            tmp ^= (1L << j);
        }
    }

    *x = tmp;
}

