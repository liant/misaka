#ifndef GATE_H_INCLUDED
#define GATE_H_INCLUDED

#include "gateconfig.h"
#include "../wrapper/wrapper.h"
#include <stdint.h>

typedef struct _Gate Gate;

Gate *GateInit(GateConfig *pconfig,Wrapper *pWrapper);
intptr_t GateRun(Gate *pgate);

#endif // GATE_H_INCLUDED
