/************************************
 *      CONTROL IO HEADER FILE      *
 * GENERAL IO STATES AND CONDITIONS *
 ************************************/
#ifndef A_CONTROLIO_h
#define A_CONTROLIO_h

#include <Arduino.h>
#include <Logging.h>
#include <enum.h>

/**************************
 * GENERAL LOGICAL STATES *
 **************************/
#define DIO_LOW 0
#define DIO_HIGH 1

/*****************************
 * GENERAL DIGITAL IO STATES *
 *****************************/
#define DIO_ON_II DIO_HIGH
#define DIO_OFF_II DIO_LOW
#define DIO_LE_II DIO_LOW // Transition from OFF to ON
#define DIO_TE_II DIO_HIGH  // Transition from ON to OFF

/****************************
 * GENERAL NC AND NO STATES *
 ****************************/
#define DIO_NO_ON_II DIO_HIGH
#define DIO_NO_OFF_II DIO_LOW

#define DIO_NC_ON_II DIO_LOW
#define DIO_NC_OFF_II DIO_HIGH

/**********************
 * GENERAL ANALOG IOS *
 **********************/
#define AIO_II DIO_LOW



/******************
 * GENERAL STATES *
 ******************/
enum ioState
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
enum netState
{
    NET_STS_NONE = 0,
    NET_STS_ON,       // Network Status ON
    NET_STS_OFF,          // Network Status OFF
    NET_STS_DISABLED,     // Network Status Disabled
    NET_STS_ERR,          // Network Status Error
    NET_STS_DISCONNECTED, // Network Status Disconnected
    NET_STS_FAILED        // Network Status Failed
};

enum portType {
    TYPE_INPUT = 0,
    TYPE_OUTPUT
};


/******************
 * GPIO PORT TYPES *
 ******************/
enum portType
{
    PORT_NONE = 0,
    PORT_DIN,     // Digital Input
    PORT_DOUT,    // Digital Output
    PORT_AIN,     // Analog Input
    PORT_AOUT,    // Analog Output
    PORT_INTP     // Interrupt pin
};


enum PIN_MODE {
    PIN_OUTPUT = 0,
    PIN_INPUT,
    PIN_INPUT_PULLUP,
    PIN_INPUT_PULLDOWN
};

/**************************
 * GENERAL HARDWARE TYPES *
 **************************/
enum controllerType
{
    CTL_NONE = 0,
    CTL_GENERAL,             // Hardware Type General
    CTL_ESP01,               // ESP-01
    CTL_ESP8266,             // ESP8266 General devKit
    CTL_ESP12E,              // ESP8266 type 12E
    CTL_ESP12F,              // ESP8266 type 12F
    CTL_ESP32,               // ESP32 General devKit
    CTL_ESP32_CAM,           // ESP32 Cam devKit
    CTL_ARDUINO_UNO,         // Arduino Uno
    CTL_ARDUINO_MEGA,        // Arduino Mega
    CTL_ARDUINO_LEONARDO     // Arduino Leonardo
};

/*************************
 *  GENERAL NODE TYPES   *
 *************************/
enum nodeType {
    NODE_Digital = 0,
    NODE_Analog
};





#endif