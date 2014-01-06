#include "gate.h"
#include "../wrapper/wrapper.h"
#include "consolepool.h"

#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <errno.h>

struct _Gate {

////客户端socket//////////////////////////////////////////
//   AStack *psocketstack;
    struct epoll_event *pevent;
    int epollfd;
    intptr_t max_events;
    intptr_t timeout;
//   LDWord flags;
    ///服务端socket///////////////////////
    Console *pListenConsole;
    ////////////////////////////////////////////
    Wrapper *pWrapper;
    ConsolePool *pConsolePool;
};

Gate *GateInit(GateConfig *pconfig,Wrapper *pWrapper)
{
    Gate *pGate;
    pGate=(Gate*)malloc(sizeof(Gate));
    pGate->max_events=pconfig->max_events;
    pGate->timeout=pconfig->timeout;
    ///////////////////////////////////////////////////////////////////
    pGate->pevent=(struct epoll_event *)malloc(sizeof(struct epoll_event)*pGate->max_events);
    pGate->epollfd=epoll_create(pGate->max_events);

    return pGate;
}

intptr_t GateRun(Gate *pGate)
{
    assert(pGate);
    int nfds;

    //LSocket *psocket;
    nfds=epoll_wait(pGate->epollfd,pGate->pevent,pGate->max_events,pGate->timeout);

    Console *pConsole;
    for(int i=0; i<nfds; i++) {
        pConsole=pGate->pevent[i].data.ptr;

        if(pConsole==0) {
            continue;
        }
        //检查是否是监听的终端
        if(pConsole==pListenConsole) {
            //
            Console *pconnect;
            pconnect=ConsolePoolAlloc(pGate->pConsolePool);

            int ret;
            socklen_t len;
            len=sizeof(struct sockaddr_in);
            Console_Accept:
            ret=accept(pconsole->id,&(pclient->addr),&len);
            if(ret<0) {
                if(errno==EAGAIN) {
                    //记录出错信息
                    trace("gate console accept error:Accept empty error!");
                    continue;
                }
                if(errno==EINTR) {
                    goto Console_Accept;
                }
                if(errno==ECONNABORTED||errno==EBADF) {
                    //listenconsole关闭
                    psocket->mode|=LSocketMode_Close;
                    //记录出错信息
                    trace("gate console accept error:Accept socket close error!");
                    continue;
                }
                if(errno==EMFILE||errno==ENFILE) {
                    trace("gate console accept error:Accept socket limite  error!");
                    continue;
                }
                LThrow(LSocketException_WrongError);
                return 0;
            }
            pclient->socket=ret;
            pclient->mode=0;
            return pclient;
            //加入epoll
            if(epoll_ctl(pset->epollfd,EPOLL_CTL_ADD,*((LInt*)psocket),&ev)<0) {
                LThrow(LSelectException_AddError);
                return;
            }
            continue;
        }
        if(pGate->pevent[i].events&EPOLLIN) {
            //进行数据wrapper操作
            WrapperBox(pGate->pWrapper,pConsole);
        }
        if(pGate->pevent[i].events&EPOLLOUT) {
            //进行数据wrapper操作
            WrapperUnbox(pGate->pWrapper,pConsole);
        }
        if(pGate->pevent[i].events&EPOLLRDHUP) {
            //表示socket被关闭
            //LSocketSet(psocket,LSocketMode_Close);
            ConsolePoolFree(pGate->pConsolePool,pConsole);

        }
    }
    //暂时挂起
    sleep(0);
    return 0;
}
