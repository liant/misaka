#ifndef CONSOLEPOOL_H_INCLUDED
#define CONSOLEPOOL_H_INCLUDED

typedef struct _Console Console;
typedef struct _ConsolePool ConsolePool;

ConsolePool *ConsolePoolCreate(int max_size);
Console *ConsolePoolAlloc(ConsolePool *pcp);
void ConsolePoolFree(ConsolePool *pcp,Console *pConsole);
void ConsolePoolClose(ConsolePool *pcp);


#endif // CONSOLEPOOL_H_INCLUDED
