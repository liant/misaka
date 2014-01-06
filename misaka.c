#include "misaka.h"
#include "stdlib.h"
#include "assert.h"
#include "gate/gate.h"
#include "misakaconfig.h"

struct _MisakaContext
{
    Gate *pGate;
    MisakaConfig *pConfig;
    int x;
    int y;
};

MisakaContext *MisakaCreate()
{
    MisakaContext *pContext;
    pContext=malloc(sizeof(MisakaContext));
    return pContext;
}
intptr_t MisakaInit(MisakaContext *pContext)
{
    assert(pContext);
    pContext->pGate=GateInit(GateConfigInit(pContext->pConfig),0);
    if(pContext->pGate==0){
        return 1;
    }
    pContext->x=3;
    pContext->y=4;
    return 0;
}
intptr_t MisakaRun(MisakaContext *pContext)
{
    assert(pContext);
    return 0;
}
