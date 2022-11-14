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
#define DIO_NO_ON_II DIO_HIGH
#define DIO_NO_OFF_II DIO_LOW

#define DIO_NC_ON_II DIO_LOW
#define DIO_NC_OFF_II DIO_HIGH

/**********************
 * GENERAL ANALOG IOS *
 **********************/
#define AIO_II DIO_LOW

// Length of Controller Name string
#define MAX_CTL_NAME 10

// Length of Sensor Name string
#define MAX_SENSOR_NAME 10

// Max quantity of allowed sensors to be connected to a controller simulteneously
#define MAX_QTY_SENSOR 5


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
    PORT_DEFAULT = 0,
    PORT_DIN,  // Digital Input
    PORT_DOUT, // Digital Output
    PORT_AIN,  // Analog Input
    PORT_AOUT, // Analog Output
    PORT_INTP  // Interrupt pin
};

enum PIN_MODE
{
    PIN_DEFAULT = 0,
    PIN_OUTPUT,
    PIN_INPUT,
    PIN_INPUT_PULLUP,
    PIN_INPUT_PULLDOWN
};

/**************************
 * GENERAL HARDWARE TYPES *
 **************************/
enum CONTROLLER_TYPE
{
    CTL_DEFAULT = 0,
    CTL_GENERAL,         // Hardware Type General
    CTL_ESP01,           // ESP-01
    CTL_ESP8266,         // ESP8266 General devKit
    CTL_ESP12E,          // ESP8266 type 12E
    CTL_ESP12F,          // ESP8266 type 12F
    CTL_ESP32,           // ESP32 General devKit
    CTL_ESP32_CAM,       // ESP32 Cam devKit
    CTL_ARDUINO_UNO,     // Arduino Uno
    CTL_ARDUINO_MEGA,    // Arduino Mega
    CTL_ARDUINO_LEONARDO // Arduino Leonardo
};

/*************************
 *  GENERAL NODE TYPES   *
 *************************/
enum NODE_TYPE
{
    NODE_DEFAULT = 0,
    NODE_DIGITAL,
    NODE_ANALOG
};

/*************************
 *   CUSTOM STRUCTURES   *
 * TO DEFINE CONTROLLERS *
 *      AND SENSORS      *
 *************************/
typedef struct
{
    char                Name[MAX_CTL_NAME]; // Name of the Controller
    CONTROLLER_TYPE     Type;    // Type of Controller
    uint16_t            pinsUsed;       // Total Number of GPIO pins used, set to -1 for no sensors
    OBJ_SYS_CONTROLLER* pSysCtl;
} OBJ_CONTROLLER;

typedef struct
{
    uint16_t        idxCTL;
    LOG_STATE       logging;
} OBJ_SYS_CONTROLLER;

typedef struct
{
    char            Name[MAX_SENSOR_NAME];  // Name of the sensor
    byte            PIN;                    // Connected PIN
    PORT_TYPE       portType;
    PIN_MODE        pinMode;                // Specific the mode type
    CTL_LIST        masterCTL;              // Connected Controller
    OBJ_SYS_IO*     pSysIO;
} OBJ_IO;

typedef struct
{
    uint16_t    idxIO;
    IO_STATE    currentState;
    IO_TYPE     ioType;             // Type: Input or output
    NODE_TYPE   SignalType;             // Digital or Analog
} OBJ_SYS_IO;

typedef struct {

} OBJ_SYSTEM;

typedef struct {

} OBJ_MODULE;





#endif