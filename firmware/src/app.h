#ifndef _APP_H
#define _APP_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"

/**
 * This enumeration defines the valid application states.  These states
 * determine the behavior of the application at various times.
 */
typedef enum {
    /* Application's state machine's initial state. */
    APP_STATE_INIT = 0,
    APP_STATE_SERVICE_TASKS,

    /* TODO: Define states used by the application state machine. */

} APP_STATES;

/**
 * This structure holds the application's data.
 */
typedef struct {
    /* The application's current state */
    APP_STATES state;

    /* TODO: Define any additional data used by the application. */

} APP_DATA;

/**
 *  This function initializes the Harmony application. It places the 
 *  application in its initial state and prepares it to run so that its 
 *  APP_Tasks function can be called.
 *
 *  All other system initialization routines should be called before calling
 *  this routine (in "SYS_Initialize").
 */
void APP_Initialize(void);


/**
 *  This routine is the Harmony Demo application's tasks function. It
 *  defines the application's state machine and core logic. The system and 
 *  application initialization ("SYS_Initialize") should be called before 
 *  calling this.
 */
void APP_Tasks(void);

#endif	/* _APP_H */
