#include <stdio.h>
#include "vaihto.h"

int main(void) {
  int x = 2;
  int y = 1;
  int z = 4;

  printf("X:%i\n",x);
  printf("Y:%i\n",y);

  vaihda(&x,&y);

  printf("X:%i\n",x);
  printf("Y:%i\n",y);

  jarjesta(&x,&y,&z);

  printf("X:%i\n",x);
  printf("Y:%i\n",y);
  printf("Z:%i\n",z);

  return 0;
}
