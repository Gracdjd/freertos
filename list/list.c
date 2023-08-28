#include "list.h"

void vListInitialiseItem(ListItem_t *const pxItem)
{
    pxItem->pvContainer = NULL;
}

void vListInitialise(List_t *const pxList)
{
    pxList->pxIndex = (ListItem_t *) &(pxList->xListEnd);
    pxList->uxNumberOfItems = portMAX_DELAY; 

    pxList->xListEnd.pxNext = ( ListItem_t * ) &( pxList->xListEnd );
    pxList->xListEnd.pxPrevious = ( ListItem_t * ) &( pxList->xListEnd );
    pxList->uxNumberOfItems = ( UBaseType_t ) 0U;
}

void vListInsertEnd(List_t * const pxList, ListItem_t * const pxNewItem)
{
    ListItem_t *const pxNext = pxList->pxIndex;
    pxNewItem->pxPrevious = pxNext->pxPrevious;
    pxNewItem->pxNext = pxNext;
    pxNext->pxPrevious = pxNewItem;

    pxNewItem->pvContainer = (void*) pxList;

    (pxList->uxNumberOfItems) ++;

}

void vListInsert(List_t *const pxList, ListItem_t *const pxNewItem)
{
    ListItem_t *pxIterator;
    const TickType_t xValueOfInsertion = pxNewItem->xItemValue;

    /*寻找要插入的位置*/
    if(xValueOfInsertion == portMAX_DELAY)
    {
        pxIterator = pxList->xListEnd.pxPrevious;
    }
    else
    {
        for(pxIterator = (ListItem_t *) &(pxList->xListEnd);
        (pxIterator->pxNext)->xItemValue <= xValueOfInsertion;
        pxIterator = pxIterator->pxNext)
        {
            //不断迭代
        }
    }
    //需要插入到pxItrerator->next
    pxNewItem->pxNext = pxIterator->pxNext;
    pxNewItem->pxPrevious = pxIterator;
    pxIterator->pxNext = pxNewItem;
    pxNewItem->pxNext->pxPrevious = pxNewItem;

    pxNewItem->pvContainer = (void*) pxList;
    (pxList->uxNumberOfItems) ++;

}
