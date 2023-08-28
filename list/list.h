#ifndef LIST_H
#define LIST_H

#include "../portmacro.h"

/// @brief node
struct xLIST_ITEM
{
    /* data */
    TickType_t xItemValue;
    struct xLIST_ITEM * pxNext;
    struct xLIST_ITEM * pxPrevious;
    void * pvOwner; //指向内核中的拥有者，通常是TCB对象
    void * pvContainer; //指向节点所在链表
};
typedef struct xLIST_ITEM ListItem_t;



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

/// @brief initialise the list
/// @param pxList 
void vListInitialise(List_t * const pxList);

void vListInsertEnd(List_t * const pxList, ListItem_t * const pxNewItem);

/// @brief 将节点按照升序排列,值相同，则新节点在旧节点后面插入
/// @param pxList 
/// @param pxItem 
void vListInsert(List_t * const pxList, ListItem_t * const pxNewItem);

/// @brief 删除指定item
/// @param pxItemToRemove 
/// @return 返回删除后的item数量
UBaseType_t uxListRemove(ListItem_t * const pxItemToRemove);

#endif
