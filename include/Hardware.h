/****************************
 * GENERAL LIBRARY TO INIT  *
 * AND PLAY WITH IO SENSORS *
 ****************************/
#ifndef A_HARDWARE_h
#define A_HARDWARE_h

#include <Arduino.h>
#include "enum.h"
#include "ControlIO.h"

/***************************
 * MASTER CONTROLLER CLASS *
 * REGISTERS CONTROLLER SO *
 *  SENSORS CAN BE ADDED   *
 ***************************/
class CController
{
private:
    uint16_t _idxController;

    CONTROLLER_TYPE _type;
    uint16_t _totalPinsUsed;
    bool _bHasSensor;

public:
    CController();
    ~CController();
    bool Init();
    bool Register(OBJ_CONTROLLER *Controller);
    bool PostRegister(); // todo  Figure out how to validate after registering or do we validate while registering?
    bool CheckHasSensor();

    char ctlName[MAX_CTL_NAME];
    bool bInited;
    bool bRegistered;
};









/* SENSOR CLASS WHICH REGISTERS
AND TRACKS SENSORS ON A CONTROLLER */
class CSensor
{
private:
    uint16_t _idxSensor;
    
    uint16_t _sensorPin;  // Pin of the sensor
    NODE_TYPE _signalType; // Analog or Digital
    IO_TYPE _sensorType;   // Input or Output
    CTL_LIST _senCTL;     // Attached Controller

public:
    CSensor();
    ~CSensor();
    bool Init();
    bool Register(OBJ_IO* pControlIO);
    bool PostRegister();
    bool setMode();

    char senName[MAX_SENSOR_NAME];
    bool bInited;
    bool bRegistered;
};

#endif