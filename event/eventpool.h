#ifndef EVENTPOOL_H_INCLUDED
#define EVENTPOOL_H_INCLUDED

#include <stdint.h>

#include "event.h"

typedef struct _EventPool EventPool;

//创建一个事件池
EventPool *EventPoolCreate(intptr_t max_events);
//分配一个事件 max_size 指事件附带数据大小
Event *EventPoolAlloc(EventPool *pep,intptr_t max_size);
void EventPoolFree(EventPool *pep,Event *pevent);
void EventClose(EventPool *pep);

#endif // EVENTPOOL_H_INCLUDED
