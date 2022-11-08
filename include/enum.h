/******************************
 * HEADER FILE TO CONSOLIDATE *
 * ALL ENUMERATIONS OF STATES *
 *       AND OTHER SHIT       *
 ******************************/

/**==============================================
 *                List of Enumerations
 *  1. ioStates
 *  2. netStates
 *  3. pinTypes
 *  
 *  
 *=============================================**/

#ifndef A_ENUM_h
#define A_ENUM_h

#include <Arduino.h>


#define MAX_CTL_QTY 5
#define MAX_SENSOR_QTY 5


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


/****************************
 * LIST ALL DIGITAL SENSORS *
 *          INPUT           *
 ****************************/
enum digitalNode_IN {
    D_Sensor0_IN_DEFAULT = 0,
    D_Sensor1_IN_TEST1,        // TEST sensor
    D_Sensor2_IN_NONE,
    D_Sensor3_IN_NONE,
    D_Sensor4_IN_NONE,
    D_Sensor5_IN_NONE,
};


/****************************
 * LIST ALL DIGITAL SENSORS *
 *         OUTPUT           *
 ****************************/
enum digitalNode_OUT {
    D_Sensor0_OUT_DEFAULT = 0,
    D_Sensor1_OUT_TEST2,        // TEST Sensor
    D_Sensor2_OUT_NONE,
    D_Sensor3_OUT_NONE,
    D_Sensor4_OUT_NONE,
    D_Sensor5_OUT_NONE,
};


/****************************
 * LIST ALL Analog SENSORS  *
 *          INPUT           *
 ****************************/
enum analogNode_IN {
    A_Sensor0_IN_DEFAULT = 0,
    A_Sensor1_IN_NONE,
    A_Sensor2_IN_NONE,
    A_Sensor3_IN_NONE,
    A_Sensor4_IN_NONE,
    A_Sensor5_IN_NONE,
};


/****************************
 * LIST ALL Analog SENSORS  *
 *          OUTPUT          *
 ****************************/
enum analogNode_OUT {
    A_Sensor0_OUT_DEFAULT = 0,
    A_Sensor1_OUT_NONE,
    A_Sensor2_OUT_NONE,
    A_Sensor3_OUT_NONE,
    A_Sensor4_OUT_NONE,
    A_Sensor5_OUT_NONE,
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