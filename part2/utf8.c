#include "utf8.h"

void utf8_koodaa(unsigned int character, unsigned char utf8[]) {
    int length;
    unsigned int x = character;
    int k = 0;
    int i = 0;

    if (x == 0) {
        k = 0;
    } else {
        while ((x >> k) != 1) {
            k++;
        }
    }

    if (k <= 7) {
        length = 1;
    } else if (k <= 11) {
        length = 2;
    } else if (k <= 16) {
        length = 3;
    } else {
        length = 4;
    }

    for (i = 0; i < length; i++) {
        utf8[i] = 0;
    }

    for (i = length - 1; i > 0; i--) {
        utf8[i] |= 0x80;
    }

    for (i = 0; i <= k; i++) {
        utf8[i / 8] |= ((x >> (k - i)) & 1) << (7 - (i % 8));
    }

    utf8[length] = '\0';
}
