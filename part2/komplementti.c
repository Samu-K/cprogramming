#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int i;
    int decimalValue = 0;
    char *binaryString = argv[1];

    int binaryLength = 0;
    while (binaryString[binaryLength] != '\0') {
        binaryLength++;
    }

    for (i = binaryLength - 1; i >= 1; i--) {
        if (binaryString[i] == '1') {
            decimalValue += pow(2, binaryLength - 1 - i);
        }
    }
    if (binaryString[0] == '1') {
        decimalValue -= pow(2, binaryLength - 1);
    }

    printf("%d\n", decimalValue);
    return 0;
}

