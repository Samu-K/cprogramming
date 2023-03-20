#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {
    int parIter;
    double input;

    int prec = atoi(argv[1]);

    for (parIter=2;parIter<argc;parIter++) {
        input= atof(argv[parIter]);
        printf("sqrt(%.*f) = %.*f\n",prec,input,prec,sqrt(input));
    }
    return 0;
}
