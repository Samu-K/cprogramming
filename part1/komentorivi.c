#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int iter;

    for (iter=1;iter<argc;iter++) {
        unsigned int len = (unsigned int)strlen(argv[iter]);
        printf("%d: %s (pituus: %d)\n",iter,argv[iter],len);
    }


    return 0;
}
