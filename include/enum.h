/******************************
 * HEADER FILE TO CONSOLIDATE *
 * ALL ENUMERATIONS OF STATES *
 *       AND OTHER SHIT       *
 ******************************/
#ifndef A_ENUM_h
#define A_ENUM_h

#include <Arduino.h>

/******************
 * GENERAL STATES *
 ******************/
enum ioStates
{
    STS_NONE = 0,
    STS_ON,     // Status ON
    STS_OFF,    // Status OFF
    STS_OK,     // Status OK
    STS_EN,     // Status Enabled
    STS_ERR     // Status Error
};

/**************************
 * GENERAL NETWORK STATES *
 **************************/
enum netStates
{
    NET_STS_NONE = 0,
    NET_STS_ON,       // Network Status ON
    NET_STS_OFF,          // Network Status OFF
    NET_STS_DISABLED,     // Network Status Disabled
    NET_STS_ERR,          // Network Status Error
    NET_STS_DISCONNECTED, // Network Status Disconnected
    NET_STS_FAILED        // Network Status Failed
};

/**************************
 * GENERAL HARDWARE TYPES *
 **************************/
enum hwTypes
{
    HW_NONE = 0,
    HW_GENERAL,             // Hardware Type General
    HW_ESP01,               // ESP-01
    HW_ESP8266,             // ESP8266 General devKit
    HW_ESP12E,              // ESP8266 type 12E
    HW_ESP12F,              // ESP8266 type 12F
    HW_ESP32,               // ESP32 General devKit
    HW_ESP32_CAM,           // ESP32 Cam devKit
    HW_ARDUINO_UNO,         // Arduino Uno
    HW_ARDUINO_MEGA,        // Arduino Mega
    HW_ARDUINO_LEONARDO     // Arduino Leonardo
};

/******************
 * GPIO PIN TYPES *
 ******************/
enum pinTypes
{
    PIN_NONE = 0,
    PIN_DIN,     // Digital Input
    PIN_DOUT,    // Digital Output
    PIN_AIN,     // Analog Input
    PIN_AOUT,    // Analog Output
    PIN_INTP     // Interrupt pin
};

/******************
 * LOGGING STATES *
 ******************/
enum loggingStates {
    LOG_NONE = 0,
    LOG_ENABLED,        // Logging Enabled
    LOG_DISABLED,       // Logging Disabled
    LOG_ERR             // Logging Error
};

#endif