#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {
	int mainIter;
	int numLen;
	int maxNum;
	int result;

	int rowIter;
	int colIter;

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	int c = atoi(argv[3]);
	int d = atoi(argv[4]);

	maxNum = b*d;
	numLen = (maxNum==0)?1:log10(maxNum)+2; 

	printf("%*s",numLen, "");
	for (mainIter=a;mainIter<=b;mainIter++) {
		printf("%*d",numLen,mainIter);
	}
	printf("\n");

	for (rowIter=c;rowIter<=d;rowIter++) {
		printf("%*d",numLen,rowIter);
		for (colIter=a;colIter<=b;colIter++) {
			result = rowIter*colIter;
			printf("%*d",numLen,result);
		}

		printf("\n");
	}
	return 0;
}
