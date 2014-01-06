#ifndef GATECONFIG_H_INCLUDED
#define GATECONFIG_H_INCLUDED

#include "../misakaconfig.h"
#include <stdint.h>

typedef struct _GateConfig{
    intptr_t max_events;
    intptr_t timeout;
} GateConfig;

GateConfig *GateConfigInit(MisakaConfig *pConfig);

#endif // GATECONFIG_H_INCLUDED
