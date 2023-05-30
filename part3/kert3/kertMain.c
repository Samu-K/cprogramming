#include "kertotaulu.h"
#include <stdio.h>

int main(void) {
  Kertotaulu *kt = luoKertotaulu(2,9,11,17);
  uint i = 0;
  uint j = 0;
  for(i = 0; i <= (kt->d - kt->c + 1); ++i)    /* Rivit */
  {
    for(j = 0; j <= (kt->b - kt->a + 1); ++j)  /* Sarakkeet */
    {
      if((i > 0) || (j > 0)) /* Onko kyseessä muu kuin kohta [0][0]? */
      {
         printf("%4u", kt->kertotaulu[i][j]); /* 4 merkin leveys. */
      }
      else
      {
         printf("    "); /* Kohtaan [0][0] vain 4 välilyöntiä. */
      }
    }
    printf("\n");
  }
  return 0;
}
