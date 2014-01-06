#include "event.h"
#include "stdint.h"

#include "../gate/console.h"

struct _Event
{
    //事件id
    uintptr_t id;
    uintptr_t len;
    //客户端id
    uintptr_t console_id;
    Console *pConsole;
    unsigned char data[0];
};
