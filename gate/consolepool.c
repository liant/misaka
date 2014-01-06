#include "consolepool.h"
#include "console.h"

#include <stdlib.h>
#include <assert.h>

typedef struct _ConsoleHandle{
    int no;
    Console console;
}ConsoleHandle;

struct _ConsolePool
{
    Console *pConsoles;
    int max_size;
    int top;
    Console **pStack;
    intptr_t maxid;
};

ConsolePool *ConsolePoolCreate(int max_size)
{
    ConsolePool *pcp;
    pcp=(ConsolePool*)malloc(sizeof(ConsolePool));
    pcp->max_size=max_size;
    pcp->pConsoles=(Console*)malloc(sizeof(Console)*pcp->max_size);
    pcp->pStack=(Console**)malloc(sizeof(Console*)*pcp->max_size);
    for(int i=0;i<pcp->max_size;i++){
        pcp->pStack[i]=&(pcp->pConsoles[i]);
    }
    pcp->top=-1;
    pcp->maxid=0;
    return pcp;
}
Console *ConsolePoolAlloc(ConsolePool *pcp)
{
    assert(pcp);
    pcp->top++;
    if(pcp->top==pcp->max_size){
        return 0;
    }
    Console *pConsole;
    pConsole=pcp->pStack[pcp->top];
    if(pcp->maxid==0)
        pcp->maxid++;
    pConsole->id=pcp->maxid;
    pcp->maxid++;
    pConsole->sockfd=-1;
    pConsole->pevent=0;
    return pConsole;
}
void ConsolePoolFree(ConsolePool *pcp,Console *pConsole)
{
    assert(pcp);
    if(pcp->top==-1){
        return;
    }
    if(pConsole){
        pcp->pStack[pcp->top]=pConsole;
        pcp->top--;
    }
}
void ConsolePoolClose(ConsolePool *pcp)
{
    if(pcp){
        if(pcp->pStack){
            free(pcp->pStack);
        }
        if(pcp->pConsoles){
            free(pcp->pConsoles);
        }
        free(pcp);
    }
}
