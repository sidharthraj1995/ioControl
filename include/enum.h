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

#include <Arduino.h>


// Length of Name string
#define MAX_NAME_LENGTH 20

// Length of Date
#define MAX_DATE_LENGTH 12 // 2022-11-24

// Max number of controller on a system, this includes both local and remote
#define MAX_QTY_CONTROLLER 3

// Max quantity of allowed sensors to be connected to a controller simulteneously
#define MAX_QTY_SENSOR 5




/******************
 * GENERAL STATES *
 ******************/
enum SYS_STATE
{
    STS_DEFAULT = 0,
    STS_ON,  // Status ON
    STS_OFF, // Status OFF
    STS_OK,  // Status OK
    STS_EN,  // Status Enabled
    STS_ERR  // Status Error
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


/***************************
 * LIST ALL THE CONTROLLER *
 *          BELOW          *
 ***************************/
enum CTL_LIST {
    CTL_LIST_DEFAULT = 0,
    CTL_00_ESP8266,         // ESP8266 devKit TEST
    // CTL_01_NONE,
    // CTL_02_NONE
    CTL_MAX_ASIZE           // MUST BE LAST!!
};

enum DEVICE_LIST {
    DEVICE_LIST_DEFAULT = 0,
    DEVICE_TEST_IN_1,
    DEVICE_TEST_IN_2,
    
    DEVICE_TEST_OUT_1,
    DEVICE_TEST_OUT_2,

    DEVICE_MAX_ASIZE
};


/*****************************
 * CONTROLLER NAME - CTL_LIST*
 *     PROCESSOR: <NAME>     *
 *  PIN: <TOTAL PIN COUNT>   *
 *****************************/
enum GPIO_00 {
    CTL00_GPIO_01_NONE =  0,
    CTL00_GPIO_02_NONE =  1,
    CTL00_GPIO_03_NONE =  2,
    CTL00_GPIO_04_NONE =  3,
    CTL00_GPIO_05_NONE =  4,
    CTL00_GPIO_06_NONE =  5,
    CTL00_GPIO_07_NONE =  6,
    CTL00_GPIO_08_NONE =  7,
    CTL00_GPIO_09_NONE =  8,
    CTL00_GPIO_10_NONE =  9,
    CTL00_GPIO_11_NONE = 10,
    CTL00_GPIO_12_NONE = 11,
    CTL00_GPIO_13_NONE = 12,
    CTL00_GPIO_14_NONE = 13,
    CTL00_GPIO_15_NONE = 14,
    CTL00_GPIO_16_NONE = 15,
    CTL00_GPIO_17_NONE = 16,
    CTL00_GPIO_18_NONE = 17,
    CTL00_GPIO_19_NONE = 18,
    CTL00_GPIO_20_NONE = 19,
    CTL00_GPIO_21_NONE = 20,
    CTL00_GPIO_22_NONE = 21,
    CTL00_GPIO_23_NONE = 22,
    CTL00_GPIO_24_NONE = 23,
    CTL00_GPIO_25_NONE = 24,
    CTL00_GPIO_26_NONE = 25,
    CTL00_GPIO_27_NONE = 26,
    CTL00_GPIO_28_NONE = 27,
    CTL00_GPIO_29_NONE = 28,
    CTL00_GPIO_30_NONE = 29,
    CTL00_GPIO_31_NONE = 30,
    CTL00_GPIO_32_NONE = 31,
    CTL00_GPIO_ASIZE                 // MUST BE LAST!!
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