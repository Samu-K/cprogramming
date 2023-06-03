#ifndef KERTOTAULU_H
#define KERTOTAULU_H

typedef unsigned int uint;

struct Kertotaulu {
  uint a,b,c,d;
  uint** kertotaulu;
};

typedef struct Kertotaulu Kertotaulu;

Kertotaulu* luoKertotaulu(uint,uint,uint,uint);

void tuhoaKertotaulu(Kertotaulu*);

#endif
