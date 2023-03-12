#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    int iter;
    
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    for (iter=a;iter<=b;iter++) {
        printf("%d: %c\n",iter,iter);
    }

    return 0;
}
