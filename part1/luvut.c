#include <stdio.h>

int main(void) {
    int j;

    for (j=0;j<=96;j++) {
        if (j%2==0 || j%3 == 0 || j%5==0) {
            continue;
        } else {
            printf("%d ",j);
        }
    }
    printf("97\n");
    return 0;
}
