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
