/******************************
 * HEADER FILE TO CONSOLIDATE *
 * ALL ENUMERATIONS OF STATES *
 *       AND OTHER SHIT       *
 ******************************/

/**==============================================
 *                List of Enumerations
 *  1. SYS_STATEs
 *  2. NET_STATEs
 *  3. pinTypes
 *  
 *  
 *=============================================**/

#ifndef A_ENUM_h
#define A_ENUM_h



// Length of Name string
#define MAX_NAME_LENGTH 20

// Length of Date
#define MAX_DATE_LENGTH 12 // 2022-11-24

// Max number of controller on a system, this includes both local and remote
#define MAX_QTY_CONTROLLER 3

// Max quantity of allowed sensors to be connected to a controller simulteneously
#define MAX_QTY_SENSOR 5

// Max quantity of GPIO pins
#define NUM_GPIO_PINS 35


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


enum MESSAGE_TYPE {
    MESSAGE = 0,
    ERROR
};

enum MESSAGE_MODULE {
    SYSTEM = 0,
    CONTROLLER,
    DEVICE,
    RTC,
    AIO
};


/******************
 * GENERAL STATES *
 ******************/
enum SYS_STATE
{
    STS_DEFAULT = 0,
    STS_INIT,
    STS_ON,         // Status ON
    STS_OFF,        // Status OFF
    STS_OK,         // Status OK
    STS_EN,         // Status Enabled
    STS_ERR         // Status Error
};

/**************************
 * GENERAL NETWORK STATES *
 **************************/
enum NET_STATE
{
    NET_STS_DEFAULT = 0,
    NET_STS_ON,           // Network Status ON
    NET_STS_OFF,          // Network Status OFF
    NET_STS_DISABLED,     // Network Status Disabled
    NET_STS_ERR,          // Network Status Error
    NET_STS_DISCONNECTED, // Network Status Disconnected
    NET_STS_FAILED        // Network Status Failed
};

/***********************
 * GENERAL ALERT TYPES *
 ***********************/
enum ALERT_TYPE {
    ALERT_DEFAULT = 0,
    ALERT_PULSE_SLOW,
    ALERT_PULSE_FAST,
    ALERT_ON,
    ALERT_OFF,
    ALERT_NONE
};

/******************
 * LOGGING STATES *
 ******************/
enum LOG_STATE {
    LOG_DEFAULT = 0,
    LOG_NONE,
    LOG_ENABLED,        // Logging Enabled
    LOG_DISABLED,       // Logging Disabled
    LOG_ERR             // Logging Error
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


/*************************
 *  GENERAL NODE TYPES   *
 *************************/
enum NODE_TYPE
{
    NODE_TYPE_DEFAULT = 0,
    NODE_TYPE_DIGITAL,
    NODE_TYPE_ANALOG
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

/***************************
 * LIST ALL THE CONTROLLER *
 *          BELOW          *
 ***************************/
enum CTL_LIST {
    CTL_LIST_DEFAULT = 0,
    CTL_00_ESP8266,         // ESP8266 devKit TEST
    // CTL_01_NONE,
    // CTL_02_NONE
    CTL_MAX_ASIZE           // !MUST BE LAST!
};

enum DEVICE_LIST {
    DEVICE_LIST_DEFAULT = 0,
    DEVICE_TEST_IN_1,
    DEVICE_TEST_IN_2,
    
    DEVICE_TEST_OUT_1,
    DEVICE_TEST_OUT_2,

    DEVICE_MAX_ASIZE        // !MUST BE LAST!
};


/*****************************
 * CONTROLLER NAME - CTL_LIST*
 *     PROCESSOR: <NAME>     *
 *  PIN: <TOTAL PIN COUNT>   *
 *****************************/
enum GPIO_ENUM {
    GPIO_00 =  0,
    GPIO_01 =  1,
    GPIO_02 =  2,
    GPIO_03 =  3,
    GPIO_04 =  4,
    GPIO_05 =  5,
    GPIO_06 =  6,
    GPIO_07 =  7,
    GPIO_08 =  8,
    GPIO_09 =  9,
    GPIO_10 = 10,
    GPIO_11 = 11,
    GPIO_12 = 12,
    GPIO_13 = 13,
    GPIO_14 = 14,
    GPIO_15 = 15,
    GPIO_16 = 16,
    GPIO_17 = 17,
    GPIO_18 = 18,
    GPIO_19 = 19,
    GPIO_20 = 20,
    GPIO_21 = 21,
    GPIO_22 = 22,
    GPIO_23 = 23,
    GPIO_24 = 24,
    GPIO_25 = 25,
    GPIO_26 = 26,
    GPIO_27 = 27,
    GPIO_28 = 28,
    GPIO_29 = 29,
    GPIO_30 = 30,
    GPIO_31 = 31,

    // Add new GPIO above
    GPIO_UNUSED,
    GPIO_ASIZE                 // !MUST BE LAST!
};

//----------------------------------------------------

/*********************************
 *    FIND GENERAL CONTROLLER    *
 *         PINOUT BELOW          *
 * USE ACCORDING TO YOUR PROJECT *
 *          CONTROLLER           *
 *********************************/


/*****************************
 * CONTROLLER NAME - VERSION *
 *     PROCESSOR: <NAME>     *
 *  PIN: <TOTAL PIN COUNT>   *
 *****************************/
//enum CTL00 {
//    CTL00_PIN01 =  0,
//    CTL00_PIN02 =  1,
//    CTL00_PIN03 =  2,
//    CTL00_PIN04 =  3,
//    CTL00_PIN05 =  4,
//    CTL00_PIN06 =  5,
//    CTL00_PIN07 =  6,
//    CTL00_PIN08 =  7,
//    CTL00_PIN09 =  8,
//    CTL00_PIN10 =  9,
//    CTL00_PIN11 = 10,
//    CTL00_PIN12 = 11,
//    CTL00_PIN13 = 12,
//    CTL00_PIN14 = 13,
//    CTL00_PIN15 = 14,
//    CTL00_PIN16 = 15,
//    CTL00_PIN17 = 16,
//    CTL00_PIN18 = 17,
//    CTL00_PIN19 = 18,
//    CTL00_PIN20 = 19,
//    CTL00_PIN21 = 20,
//    CTL00_PIN22 = 21,
//    CTL00_PIN23 = 22,
//    CTL00_PIN24 = 23,
//    CTL00_PIN25 = 24,
//    CTL00_PIN26 = 25,
//    CTL00_PIN27 = 26,
//    CTL00_PIN28 = 27,
//    CTL00_PIN29 = 28,
//    CTL00_PIN30 = 29,
//    CTL00_PIN31 = 30,
//    CTL00_PIN32 = 31
//};


//----------------------------------------------------



#endif