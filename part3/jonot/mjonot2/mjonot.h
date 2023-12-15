#ifndef MJONOT_H
#define MJONOT_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char ** jarjesta_mjt(char **mjt,size_t lkm,int (*vrt)(const char*, const char*));

#endif
