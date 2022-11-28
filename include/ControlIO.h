/************************************
 *      CONTROL IO HEADER FILE      *
 * GENERAL IO STATES AND CONDITIONS *
 ************************************/
#ifndef A_CONTROLIO_h
#define A_CONTROLIO_h

#include <Arduino.h>
#include "enum.h"

/* DO NOT CHANGE ANY DEFINEs BELOW */

/**************************
 * GENERAL LOGICAL STATES *
 **************************/
#define DIO_LOW     0
#define DIO_HIGH    1

/********************************
 * GENERAL DIGITAL INPUT STATES *
 ********************************/
#define DIO_ON_II   DIO_HIGH
#define DIO_OFF_II  DIO_LOW
#define DIO_LE_II   DIO_LOW  // Transition from OFF to ON
#define DIO_TE_II   DIO_HIGH // Transition from ON to OFF

/*********************************
 * GENERAL DIGITAL OUTPUT STATES *
 *********************************/
#define DIO_ON_IO   DIO_HIGH
#define DIO_OFF_IO  DIO_LOW
#define DIO_LE_IO   DIO_LOW  // Transition from OFF to ON
#define DIO_TE_IO   DIO_HIGH // Transition from ON to OFF

/****************************
 * GENERAL NC AND NO STATES *
 ****************************/
#define DIO_NO_ON_II     DIO_HIGH
#define DIO_NO_OFF_II    DIO_LOW

#define DIO_NC_ON_II     DIO_LOW
#define DIO_NC_OFF_II    DIO_HIGH

/**********************
 * GENERAL ANALOG IOS *
 **********************/
#define AIO_II DIO_LOW


/* Device Scan rate */
enum SCAN_RATE {
    SCAN_DEFAULT = 0,
    SCAN_1 = 2,
    SCAN_2 = 5,
    SCAN_3 = 20
};


enum IO_TYPE
{
    TYPE_DEFAULT = 0,
    TYPE_INPUT,
    TYPE_OUTPUT
};

/******************
 * GPIO PORT TYPES *
 ******************/
enum PORT_TYPE
{
    PORT_TYPE_DEFAULT = 0,
    PORT_TYPE_DIN,           // Digital Input
    PORT_TYPE_DOUT,          // Digital Output
    PORT_TYPE_AIN,           // Analog Input
    PORT_TYPE_AOUT,          // Analog Output
    PORT_TYPE_INTP           // Interrupt pin
};

enum PIN_MODE
{
    PIN_MODE_DEFAULT = 0,
    PIN_MODE_OUTPUT,
    PIN_MODE_INPUT,
    PIN_MODE_INPUT_PULLUP,
    PIN_MODE_INPUT_PULLDOWN
};

/**************************
 * GENERAL HARDWARE TYPES *
 **************************/
enum CONTROLLER_TYPE
{
    CTL_TYPE_DEFAULT = 0,
    CTL_TYPE_GENERAL,         // Hardware Type General
    CTL_TYPE_ESP01,           // ESP-01
    CTL_TYPE_ESP8266,         // ESP8266 General devKit
    CTL_TYPE_ESP12E,          // ESP8266 type 12E
    CTL_TYPE_ESP12F,          // ESP8266 type 12F
    CTL_TYPE_ESP32,           // ESP32 General devKit
    CTL_TYPE_ESP32_CAM,       // ESP32 Cam devKit
    CTL_TYPE_ARDUINO_UNO,     // Arduino Uno
    CTL_TYPE_ARDUINO_MEGA,    // Arduino Mega
    CTL_TYPE_ARDUINO_LEONARDO // Arduino Leonardo
};

/*************************
 *  GENERAL NODE TYPES   *
 *************************/
enum NODE_TYPE
{
    NODE_TYPEDEFAULT = 0,
    NODE_TYPEDIGITAL,
    NODE_TYPEANALOG
};





#endif