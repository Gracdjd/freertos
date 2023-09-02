#if !defined(PROGDEFS_H)
#define PROGDEFS_H

#include "portmacro.h"
typedef void (*TaskFunction_t) (void *);

#define  pdFALSE (( BaseType_t )0)
#define pdTRUE ( ( BaseType_t ) 1 )

#define pdPASS ( pdTRUE )
#define pdFAIL ( pdFALSE )

#endif // PROGDEFS_H
