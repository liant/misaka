#ifndef MISAKA_H_INCLUDED
#define MISAKA_H_INCLUDED

#include "stdint.h"

typedef struct _MisakaContext MisakaContext;

MisakaContext *MisakaCreate();
intptr_t MisakaInit(MisakaContext *pContext);
intptr_t MisakaRun(MisakaContext *pContext);

#endif // MISAKA_H_INCLUDED
