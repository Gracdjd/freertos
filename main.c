#include "list/list.h"
#include "task/task.h"
#include <stdio.h>
int main()
{
    ListItem_t node;
    vListInitialiseItem(&node);
    node.xItemValue = 1000;

    List_t l;
    vListInitialise(&l);

    vListInsert(&l, &node);

    printf("hello world\n");
    printf("%lu\n", l.uxNumberOfItems);
    printf("%u\n", l.pxIndex->xItemValue);
    printf("%p\n", l.pxIndex);

    printf("%p\n", l.pxIndex->pxPrevious);
    printf("%p\n", l.pxIndex->pxNext);

    return 0;
}