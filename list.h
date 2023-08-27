#ifndef LIST_H
#define LIST_H

#include "portmacro.h"

/// @brief node
struct XLIST_ITEM
{
    /* data */
    TickType_t xItemValue;
    struct xLIST_ITEM * pxNext;
    struct xLIST_ITEM * pxPrevious;
    void * pvOwner; //指向内核中的拥有者，通常是TCB对象
    void * pvContainer; //指向节点所在链表
};
typedef struct XLIST_ITEM ListItem_t;



struct xMINI_LIST_ITEM
{
    TickType_t xItemValue; /* 辅助值，用于帮助节点做升序排列 */
    struct xLIST_ITEM * pxNext; /* 指向链表下一个节点 */
    struct xLIST_ITEM * pxPrevious; /* 指向链表前一个节点 */
};
typedef struct xMINI_LIST_ITEM MiniListItem_t; /* 精简节点数据类型重定义 */

typedef struct xLIST
{
    /* data */
    UBaseType_t uxNumberOfItems; //节点数量
    ListItem_t * pxIndex;; //链表节点索引指针
    MiniListItem_t  xListEnd; //最后一个节点

}List_t;



/// @brief initialise the node
/// @param pxItem 
void vListInitialiseItem(ListItem_t * const pxItem);

void vListInitialise(List_t * const pxList);
  
#endif
