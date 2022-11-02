/****************************
 * GENERAL LIBRARY TO INIT  *
 * AND PLAY WITH IO SENSORS *
 ****************************/
#ifndef A_HARDWARE_h
#define A_HARDWARE_h

#include <Arduino.h>
#include "enum.h"
#include "ControlIO.h"

class CController
{
private:
    CTL_LIST _Controllers;
    uint16_t _qtyController;
    uint16_t _qtySensor;
    controllerType _typeCTL;

public:
    CController(/* args */);
    ~CController();
    bool Init();
    bool Register(String ctlName, controllerType ctlType, uint16_t sensors);
    bool AddSensor();
    
    String ctlName;
    bool bInited;
    bool bValidated; 
};



class CSensor
{
private:
    uint16_t _pinSensor;
    nodeType SensorType;
public:
    CSensor(/* args */);
    ~CSensor();
    bool Init();
    bool Register(uint16_t Pin, byte Type);
};




#endif