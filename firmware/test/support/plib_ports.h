#ifndef __DUMMY_PLIB_H__
#define __DUMMY_PLIB_H__

typedef uint16_t        PORTS_DATA_MASK;
typedef uint32_t        PORTS_DATA_TYPE;

#include "peripheral/ports/processor/ports_processor.h"

void PLIB_PORTS_PinSet(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos );
void PLIB_PORTS_PinClear(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos );

#endif // __DUMMY_PLIB_H__
