/********************************
 * LIBRARY THAT HANDLES LOGGING *
 *    AND PRINTING OF EVENTS    *
 ********************************/
#ifndef A_LOGGING_h
#define A_LOGGING_h

#include <Arduino.h>

#include <ControlIO.h>
#include <enum.h>

/******************
 * LOGGING STATES *
 ******************/
enum loggingState {
    LOG_NONE = 0,
    LOG_ENABLED,        // Logging Enabled
    LOG_DISABLED,       // Logging Disabled
    LOG_ERR             // Logging Error
};




#endif