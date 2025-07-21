#ifndef COLLBR_HEAP_H_
#define COLLBR_HEAP_H_

#include "Defs.h"

tPtr newAlloc(tUSz allocSz);
void deAlloc(tPtr ptr);
tPtr reAlloc(tPtr ptr, tUSz newSz);
tPtr numAlloc(tUSz num, tUSz szOf);

#endif//COLLBR_HEAP_H_