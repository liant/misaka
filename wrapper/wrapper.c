#include "wrapper.h"

struct _Wrapper
{
    //整个网络的上下文
  //  MisakaContext *pContext;
};

//封箱操作
intptr_t WrapperBox(Wrapper *pWrapper,Console *pConsole)
{
    //对数据封箱,生成event
    return 0;
}
//拆箱操作
intptr_t WrapperUnbox(Wrapper *pWrapper,Console *pConsole)
{
    //解析当前event,拆箱还原成原始数据
    return 0;
}
