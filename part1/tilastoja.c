#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	int i,j,k;
	int lkm = argc-1;
	int freq = 0;
	int printIter=0;
	int dupe=0;

    double* numbers = malloc(lkm);
	double* printed = malloc((int)floor(argc/2));
    double smallest, largest;

	int unique_count = 0, max_freq = 0;
	int* freq_numbers = malloc(lkm); 
	int freq_count = 0;

    for (i = 0; i < lkm; i++) {
        numbers[i] = strtod(argv[i+1], NULL);
        if (i == 0) {
            smallest = numbers[i];
            largest = numbers[i];
        } else {
            if (numbers[i] < smallest) {
                smallest = numbers[i];
            }
            if (numbers[i] > largest) {
                largest = numbers[i];
            }
        }
    }

    printf("Pienin: %f\n", smallest);
    printf("Suurin: %f\n", largest);

    for (i = 0; i < lkm; i++) {
        freq=0; 
        for (j = 0; j < lkm; j++) {
            if (numbers[i] == numbers[j]) {
                freq++;
            }
        }
        if (freq == 1) {
            unique_count++;
            if (unique_count == 1) {
                printf("Ainutlaatuiset:");
            }
			printf(" %f", numbers[i]);
			
                    }
        if (freq > max_freq) {
            max_freq = freq;
        }
    }

    if (unique_count > 0) {
        printf("\n");
    }

    for (i = 0; i < lkm; i++) {
        freq_numbers[i] = 0;
        for (j = 0; j < lkm; j++) {
            if (numbers[i] == numbers[j]) {
                freq_numbers[i]++;
            }
        }
        if (freq_numbers[i] == max_freq) {
            freq_count++;
            if (freq_count == 1 && max_freq>1) {
                printf("Useimmiten esiintyneet (%d kertaa):", max_freq); 
			}
			for (k=0;k<printIter;k++) {
				if (printed[k] == numbers[i]) {
					dupe=1;
					break;
				}
			}
			if (dupe==0 && max_freq>1) {
	            printf(" %f", numbers[i]);
				printed[printIter] = numbers[i];
				printIter++;
			}
			dupe = 0;
        }
    }
	free(numbers);
	free(printed);
	free(freq_numbers);

    if (freq_count > 0 && max_freq>1) {
        printf("\n");
    }

    return 0;
}

