#include "eventpool.h"

#include <stdlib.h>
#include <assert.h>

struct _EventPool{
    int test;
};

//创建一个事件池
EventPool *EventPoolCreate(intptr_t max_events)
{
    EventPool *pep;
    pep=(EventPool*)malloc(sizeof(EventPool));
    pep->test=max_events;
    return pep;
}

//分配一个事件 max_size 指事件附带数据大小
Event *EventPoolAlloc(EventPool *pep,intptr_t max_size)
{
    assert(pep);
    return 0;
}
void EventPoolFree(EventPool *pep,Event *pevent)
{
    assert(pep);
}

void EventClose(EventPool *pep)
{
    free(pep);
}
