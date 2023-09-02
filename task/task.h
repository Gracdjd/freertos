#if !defined(TASK_H)
#define TASK_H

#include "../portmacro.h"
#include "../list/list.h"
typedef struct tskTaskControlBlock
{
    volatile StackType_t *pxTopOfStack; //栈顶

    ListItem_t xStateListItem;

    StackType_t *pxStack; //栈起始地址

    char pcTaskName[configMAX_TASK_NAME_LEN];

} tskTCB;

typedef tskTCB TCB_t;

//静态分配
#if(configSUPPORT_STATIC_ALLOCATION == 1)

#endif
#endif // TASK_H
