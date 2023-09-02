#if !defined(TASK_H)
#define TASK_H

// #include "../portable.h"

#include "../projdefs.h"
#include "../list/list.h"

typedef struct tskTaskControlBlock
{
    volatile StackType_t *pxTopOfStack; //栈顶

    ListItem_t xStateListItem;
    
    StackType_t *pxStack; //栈起始地址

    char pcTaskName[configMAX_TASK_NAME_LEN];

} tskTCB;

typedef tskTCB TCB_t;

typedef void * TaskHandle_t;

TaskHandle_t xTaskCreateStatic( TaskFunction_t pxTaskCode,
   const char * const pcName, 
   const uint32_t ulStackDepth, 
   void * const pvParameters, 
   StackType_t * const puxStackBuffer, 
   TCB_t * const pxTaskBuffer );
// //静态分配
// #if(configSUPPORT_STATIC_ALLOCATION == 1)

static void prvInitialiseNewTask(TaskFunction_t pxTaskCode, const char *const pcName, 
    const uint32_t ulStackDepth, void *const pvParameters,
     TaskHandle_t *const pxCreatedTask, TCB_t *pxNewTCB);


#endif // TASK_H
