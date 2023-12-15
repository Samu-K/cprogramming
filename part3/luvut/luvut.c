#include <stdio.h>
#include <stdlib.h>

double getSum(double* arr, size_t n) {
  size_t i=0;
  double sum=0;
  for(i=0;i<n;i++) {
    sum += arr[i];
  }

  return sum;
}

double getAvg(double* arr, size_t n) {
  double sum=0;
  sum=getSum(arr,n);
  return sum/n;
}

static int dblVrt(const void *a, const void *b) {
  const double* x = a;
  const double* y = b;
  return *x > *y;
}

int main(void) {
  size_t i=0;
  size_t j=0;
  size_t arrSize=2;
  double inpValue=0;
  int scanState=1;
  int capacity=0;


  typedef unsigned long ulong;
  ulong curAlloc=0;
  ulong newAlloc=0;

  double* inputArr = malloc(arrSize*sizeof(double));
  capacity=2*sizeof(double);

  while(1) { 
    scanState = scanf("%lf",&inpValue);
    if (scanState != 1) {
      break;
    }
    newAlloc = sizeof(inpValue);

    if(curAlloc+newAlloc > capacity) {
      arrSize *=2;
      inputArr = realloc(inputArr,arrSize*sizeof(double));
      capacity = arrSize *sizeof(double);

    }
    inputArr[i] = inpValue;
    i++;
    curAlloc += newAlloc; 
  }

  inputArr = realloc(inputArr,i*sizeof(double));
  qsort(inputArr, i, sizeof(double), dblVrt);

  printf("Luettiin %ld lukua:",i);
  for(j=0;j<i;j++) {
    printf(" %.3lf",inputArr[j]);
  }
  printf("\n");
  printf("Summa: %.3lf\n",getSum(inputArr,i));
  printf("Keskiarvo: %.3lf\n",getAvg(inputArr,i));

  free(inputArr);
  return 0;
}
