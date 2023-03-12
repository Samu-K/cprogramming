#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
   int rowNum=0;
   int colNum=0;
   int result;
   int iter;
   int rowIter;
   int headerIter;

   printf("%*s",4,"x");
   for (headerIter=1; headerIter<16; headerIter++) {
        printf("%*d",4,headerIter);
   }
   printf("\n");

   for (iter=0;iter<15;iter++) {
        rowNum++;
        printf("%*d",4,rowNum);
        for (rowIter=0;rowIter<15;rowIter++) {
            colNum++;
            result = rowNum*colNum;

            printf("%*d",4,result);

        }
        printf("\n");
        colNum=0;
   }

   return 0;
}
