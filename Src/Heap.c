#include "Defs.h"
#include "Heap.h"

void memSet(tPtr addr, tUSz num, tU8 val)
{
	for (tUSz iI = 0LLU; iI < num; ++iI) ((tU8 *)addr)[iI] = val;
}

void memZr(tPtr addr, tUSz num)
{
	memSet(addr, num, 0LLU);
}

void memMv(tPtr src, tPtr dst, tUSz lng)
{
	if ((tUSz)src < (tUSz)dst && (tUSz)src + lng >= (tUSz)dst) for (tUSz iI = lng; iI > 0LLU; --iI) ((tU8 *)dst)[iI - 1LLU] = ((const tU8 *)src)[iI - 1LLU];
	else for (tUSz iI = 0LLU; iI < lng; ++iI) ((tU8 *)dst)[iI] = ((const tU8 *)src)[iI];
}

void memCpy(const tPtr src, tPtr dst, tUSz lng)
{
	for (tUSz iI = 0LLU; iI < lng; ++iI) ((tU8 *)dst)[iI] = ((const tU8 *)src)[iI];
}

#define HEAP_SZ 0X0800000
static tU8 PSEUDO_HEAP_MEM[HEAP_SZ] = {0};
struct _tAllcBlk
{
	struct _tAllcBlk *nxt;
	tUSz lng;
};
static struct _tAllcBlk *frst = Null;

tPtr newAlloc(tUSz sz)
{
	struct _tAllcBlk newBlk = {.lng = sz, .nxt = Null};
	if (frst == Null)
	{
		if (sizeof(newBlk) + newBlk.lng > HEAP_SZ) return Null;
		*((struct _tAllcBlk *)PSEUDO_HEAP_MEM) = newBlk;
		frst = (struct _tAllcBlk *)PSEUDO_HEAP_MEM;
		return (tPtr)((tUSz)PSEUDO_HEAP_MEM + sizeof(struct _tAllcBlk));
	}
	if (frst != (struct _tAllcBlk *)PSEUDO_HEAP_MEM)
	{
		if ((tUSz)PSEUDO_HEAP_MEM + sizeof(struct _tAllcBlk) + newBlk.lng <= (tUSz)frst)
		{
			newBlk.nxt = frst;
			frst = (struct _tAllcBlk *)PSEUDO_HEAP_MEM;
			return (tPtr)((tUSz)PSEUDO_HEAP_MEM + sizeof(struct _tAllcBlk));
		}
	}
	struct _tAllcBlk *tmp = frst;
	while (tmp != Null)
	{
		if (tmp->nxt == Null)
		{
			if (((tUSz)tmp + sizeof(*tmp) + tmp->lng) + sizeof(newBlk) + newBlk.lng < HEAP_SZ + (tUSz)PSEUDO_HEAP_MEM)
			{
				struct _tAllcBlk *newAddr = (struct _tAllcBlk *)((tUSz)tmp + sizeof(newBlk) + tmp->lng);
				tmp->nxt = newAddr;
				*newAddr = newBlk;
				return (struct _tAllcBlk *)((tUSz)newAddr + sizeof(newBlk));
			}
			else return Null;
		}
		else if (((tUSz)tmp + sizeof(*tmp) + tmp->lng) + sizeof(newBlk) + newBlk.lng < tmp->nxt)
		{
			struct _tAllcBlk *newAddr = ((struct _tAllcBlk *)(tUSz)tmp + sizeof(*tmp) + tmp->lng);
			newBlk.nxt = tmp->nxt;
			tmp->nxt = newAddr;
			*newAddr = newBlk;
			return (struct _tAllcBlk *)((tUSz)newAddr + sizeof(newBlk));
		}
		tmp = tmp->nxt;
	}
	return Null;
}

void deAlloc(tPtr ptr)
{
	return;
}

tPtr reAlloc(tPtr ptr, tUSz newSz)
{
	return Null;
}

tPtr numAlloc(tUSz num, tUSz szOf)
{
	return Null;
}