#include "kuukaudet.h"
#include <string.h>

const char *KK_NIMET[KK_LKM] = {
    "tammikuu",
    "helmikuu",
    "maaliskuu",
    "huhtikuu",
    "toukokuu",
    "kesäkuu",
    "heinäkuu",
    "elokuu",
    "syyskuu",
    "lokakuu",
    "marraskuu",
    "joulukuu"
};


const char KK_PAIVAT[2][KK_LKM] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int karkausvuosi(int vuosiluku) {
  if ((vuosiluku % 4 ==  0 && vuosiluku % 100 != 0) || vuosiluku % 400 == 0) {
    return 1;
  }
  return 0;
}

int kkPituus(const char *kkNimi, int vuosiluku) {
    int i;
    for (i = 0; i < KK_LKM; i++) {
        if (strcasecmp(kkNimi, KK_NIMET[i]) == 0) {
            return KK_PAIVAT[karkausvuosi(vuosiluku)][i];
        }
    }
    return -1;
}
