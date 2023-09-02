#include "task.h"

#if(configSUPPORT_STATIC_ALLOCATION == 1)
TaskHandle_t xTaskCreateStatic(TaskFunction_t pxTaskCode, const char *const pcName, 
    const uint32_t ulStackDepth, void *const pvParameters, StackType_t *const puxStackBuffer,
     TCB_t *const pxTaskBuffer)
{
    TCB_t *pxNewTCB;
    TaskHandle_t xReturn; 

    if ( ( pxTaskBuffer != NULL ) && ( puxStackBuffer != NULL ) )
    {
        pxNewTCB = ( TCB_t * ) pxTaskBuffer;
        pxNewTCB->pxStack = (StackType_t * ) puxStackBuffer;

        //创建新任务
        prvInitialiseNewTask(pxTaskCode, pcName, ulStackDepth,pvParameters, xReturn, pxNewTCB);
    }

    else
    {
        xReturn = NULL;
    }
    return xReturn;
}
static void prvInitialiseNewTask(TaskFunction_t pxTaskCode, const char *const pcName, 
    const uint32_t ulStackDepth, void *const pvParameters,
     TaskHandle_t *const pxCreatedTask, TCB_t *pxNewTCB)
{
    StackType_t *pxTopOfStack;
    UBaseType_t x;

    //获取栈顶位置
    pxTopOfStack = pxNewTCB->pxStack +(ulStackDepth - (uint32_t)1);
    //向下取8字节对齐
    pxTopOfStack = ( StackType_t * ) \
    ( ( ( uint32_t ) pxTopOfStack ) & ( ~( ( uint32_t ) 0x0007 ) ) );//0xFFFF8,低三位被清除

    /* 将任务的名字存储在 TCB 中 */ 
    for ( x = ( UBaseType_t ) 0; x < ( UBaseType_t ) configMAX_TASK_NAME_LEN; x++ )
    {
        pxNewTCB->pcTaskName[ x ] = pcName[ x ];
        
        if ( pcName[ x ] == 0x00 )
        {
        break;
        }
    }

    pxNewTCB->pcTaskName[ configMAX_TASK_NAME_LEN - 1 ] = '\0';
    vListInitialiseItem( &( pxNewTCB->xStateListItem ) );
    listSET_LIST_ITEM_OWNER( &( pxNewTCB->xStateListItem ), pxNewTCB );

    pxNewTCB->pxTopOfStack = pxPortInitialiseStack( pxTopOfStack,
    pxTaskCode,
    pvParameters );


}
#endif