#ifndef KUUKAUDET_H
#define KUUKAUDET_H

enum {
    TAMMIKUU,
    HELMIKUU,
    MAALISKUU,
    HUHTIKUU,
    TOUKOKUU,
    KESAKUU,
    HEINAKUU,
    ELOKUU,
    SYYSKUU,
    LOKAKUU,
    MARRASKUU,
    JOULUKUU,
    KK_LKM
};

extern const char *KK_NIMET[KK_LKM];
extern const char KK_PAIVAT[2][KK_LKM];

int karkausvuosi(int vuosiluku);
int kkPituus(const char *kkNimi, int vuosiluku);

#endif
