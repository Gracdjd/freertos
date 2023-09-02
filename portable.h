#if !defined(PORTABLE_H)
#define PORTABLE_H

#include "portmacro.h"

#include "projdefs.h"
StackType_t *pxPortInitialiseStack( StackType_t *pxTopOfStack, TaskFunction_t pxCode, void *pvParameters );
BaseType_t xPortStartScheduler( void );

#define portINITIAL_XPSR ( 0x01000000 )
#define portSTART_ADDRESS_MASK ( ( StackType_t ) 0xfffffffeUL )

#endif // PORTABLE_H
