#ifndef PORTMACRO_H
#define PORTMACRO_H

#include "stdint.h"
#include "stddef.h"
#include "freertosconfig.h"

#define portCHAR char
#define portFLOAT float
#define portDOUBLE double
#define portLONG long
#define portSHORT short
#define portSTACK_TYPE uint32_t
#define portBASE_TYPE long

typedef portSTACK_TYPE StackType_t;
typedef long BaseType_t;
typedef unsigned long UBaseType_t;
 

#if( configUSE_16_BIT_TICKS == 1 )
typedef uint16_t TickType_t;
#define portMAX_DELAY ( TickType_t ) 0xffff
#else
typedef uint32_t TickType_t; 
#define portMAX_DELAY ( TickType_t ) 0xffffffffUL
#endif

 /* 初始化节点的拥有者 */
#define listSET_LIST_ITEM_OWNER( pxListItem, pxOwner )\
( ( pxListItem )->pvOwner = ( void * ) ( pxOwner ) )
/* 获取节点拥有者 */
#define listGET_LIST_ITEM_OWNER( pxListItem )\
( ( pxListItem )->pvOwner )

/* 初始化节点排序辅助值 */
#define listSET_LIST_ITEM_VALUE( pxListItem, xValue )\
( ( pxListItem )->xItemValue = ( xValue ) )
 
/* 获取节点排序辅助值 */
#define listGET_LIST_ITEM_VALUE( pxListItem )\
( ( pxListItem )->xItemValue )
 
/* 获取链表根节点的节点计数器的值 */
#define listGET_ITEM_VALUE_OF_HEAD_ENTRY( pxList )\
( ( ( pxList )->xListEnd ).pxNext->xItemValue )
 
/* 获取链表的入口节点 */
#define listGET_HEAD_ENTRY( pxList )\
( ( ( pxList )->xListEnd ).pxNext )
 
/* 获取节点的下一个节点 */
#define listGET_NEXT( pxListItem )\
( ( pxListItem )->pxNext )
 
/* 获取链表的最后一个节点 */
#define listGET_END_MARKER( pxList )\
( ( ListItem_t const * ) ( &( ( pxList )->xListEnd ) ) )

/* 判断链表是否为空 */
#define listLIST_IS_EMPTY( pxList )\
( ( BaseType_t ) ( ( pxList )->uxNumberOfItems == ( UBaseType_t ) ) )
 
/* 获取链表的节点数 */
#define listCURRENT_LIST_LENGTH( pxList )\
( ( pxList )->uxNumberOfItems )
 
/* 获取链表第一个节点的 OWNER，即 TCB */
#define listGET_OWNER_OF_NEXT_ENTRY( pxTCB, pxList ) \
{ \
List_t * const pxConstList = ( pxList ); \
/* 节点索引指向链表第一个节点 */ \
( pxConstList )->pxIndex = ( pxConstList )->pxIndex->pxNext; \
/* 这个操作有啥用？ */ \
if( ( void * ) ( pxConstList )->pxIndex == ( void * ) &( ( pxConstList )->xListEnd ) ) \
{ \
( pxConstList )->pxIndex = ( pxConstList )->pxIndex->pxNext; \
} \
/* 获取节点的 OWNER，即 TCB */ \
( pxTCB ) = ( pxConstList )->pxIndex->pvOwner; \
 }

#endif