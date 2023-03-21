#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {
	double bottom, topPos, topNeg, sqrIn;

	double a = atof(argv[1]);
	double b = atof(argv[2]);
	double c = atof(argv[3]);

	bottom = 2*a-argc+argc;
	sqrIn = pow(b,2)-4*a*c;
	topPos = (-1)*b+sqrt(sqrIn);
	topNeg = (-1)*b-sqrt(sqrIn);

	if (sqrIn < 0) {
		printf("Ei ratkaisua\n");
	} else if (sqrIn == 0) {
		printf("%.3f\n",((-1)*b)/(bottom));
	} else {
		if ((topPos/bottom) < (topNeg/bottom)) {
			printf("%.3f %.3f\n", (topPos/bottom), (topNeg/bottom));
		} else {
			
		printf("%.3f %.3f\n", (topNeg/bottom), (topPos/bottom));
		}
	}

	return 0;
}
