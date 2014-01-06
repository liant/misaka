#ifndef WRAPPER_H_INCLUDED
#define WRAPPER_H_INCLUDED

#include "../event/event.h"
#include <stdint.h>

typedef struct _Wrapper Wrapper;
typedef struct _Console Console;
//封箱操作
intptr_t WrapperBox(Wrapper *pWrapper,Console *pConsole);
//拆箱操作
intptr_t WrapperUnbox(Wrapper *pWrapper,Console *pConsole);
#endif // WRAPPER_H_INCLUDED
