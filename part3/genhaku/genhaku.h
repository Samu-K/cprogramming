#ifndef GENHAKU_H
#define GENHAKU_H
#include <stdlib.h> 

size_t etsi(void *search, 
            size_t searchSize, 
            void *find, 
            size_t findSize, 
            size_t byteSize); /* gives size for table elems */
#endif
