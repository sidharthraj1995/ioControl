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
#define DIO_OFF 0
#define DIO_ON 1

/*****************************
 * GENERAL DIGITAL IO STATES *
 *****************************/
#define DIO_ON_II DIO_ON
#define DIO_OFF_II DIO_OFF
#define DIO_LE_II DIO_OFF // Transition from OFF to ON
#define DIO_TE_II DIO_ON  // Transition from ON to OFF

/****************************
 * GENERAL NC AND NO STATES *
 ****************************/
#define DIO_NO_ON_II DIO_ON
#define DIO_NO_OFF_II DIO_OFF

#define DIO_NC_ON_II DIO_OFF
#define DIO_NC_OFF_II DIO_ON

/**********************
 * GENERAL ANALOG IOS *
 **********************/
#define AIO_II DIO_OFF


#endif