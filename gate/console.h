#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#include <stdint.h>

typedef struct _Console
{
    uintptr_t id;
    int sockfd;
    struct epoll_event *pevent;
} Console;

Console *ConsoleOpen(Console *pConsole);
void ConsoleClose(Console *pConsole);


#endif // CONSOLE_H_INCLUDED
