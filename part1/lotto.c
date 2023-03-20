#include <stdio.h>
#include <stdlib.h>

int count_matches(int arr1[], int arr2[], int* matches) {
    int i;
    int j;

    int count = 0;

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            if (arr1[i] == arr2[j]) {
                count++;
                matches[count]=arr1[i];
                break;
            }
        }
    }
    return count;
}

int main(int argc, char** argv) {
    int paramIter;
    int listIter;

    int x;

    int winRow[7];
    int guess[7];
    int correct[7]={0};

    int corrNum=0;

    listIter=0;
    for (paramIter=1;paramIter<=7;paramIter++) {
        winRow[listIter]=atoi(argv[paramIter]);
        listIter++;
    }

    listIter=0;
    for (paramIter=paramIter;paramIter<=14;paramIter++) {
        guess[listIter]=atoi(argv[paramIter]);
        listIter++;
    }

    printf("Voittorivi:");
    for (listIter=0;listIter<7;listIter++) {
        x=winRow[listIter];
        printf(" %d",x);
    }
    printf("\nLottorivi:");
    for (listIter=0;listIter<7;listIter++) {
        x=guess[listIter];
        printf(" %d",x);
    }
    printf("\n");

    corrNum = count_matches(guess,winRow,correct);

    if (corrNum==0) {
        printf("Ei yhtään oikein!\n");
    } else {
        printf("%d oikein:", corrNum);
        for (listIter=0;listIter<=corrNum;listIter++) {
            if (correct[listIter] == 0) {
                continue;
            }
            printf(" %d",correct[listIter]);
        }
        printf("\n");
    }
    return 0;
}
