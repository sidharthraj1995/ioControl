/****************************
 * GENERAL LIBRARY TO INIT  *
 * AND PLAY WITH IO SENSORS *
 ****************************/
#ifndef A_HARDWARE_h
#define A_HARDWARE_h

#include <Arduino.h>
#include "enum.h"
#include "ControlIO.h"
#include "ObjRtc.h"

/* How do you wanna approach this? have a master class and then derive controller
and deviceIO CLASS out of it?
how do you want to handle deviceIO  ---->> it needs to be forked into II and IO

what is shared between these class? why use inheritence?

 */

/***************************************************
 *                  CLASS SYSTEM                   *
 * THIS IS THE MASTER CLASS THAT HOLDS CONTROLLERS *
 *                  AND DEVICEIOS                  *
 ***************************************************/
class CSystem
{
private:
    bool bInit;
    bool bRegistered;

public:
    CSystem();
    ~CSystem();
    bool Init();
    bool Register();

    // OBJ_CONTROLLER* pCTL;
};



class CController
{
private:
    
protected:
    OBJ_CONTROLLER* pCtl;

public:
    CController();
    ~CController();
    bool Init(OBJ_CONTROLLER* ctl);
    bool Register();

    bool ValidateController();      // Method used to validate controller defined parameters

    bool bInit;
    bool bRegistered;
};


/* THis is where you define your Devices
and IOs.
Derived class */ 
class CDeviceIO: public CController
{
private:
    bool bInit;
    bool bRegister;
    
protected:


public:
    CDeviceIO();
    ~CDeviceIO();
    bool Init();
    

    uint16_t    QtyDevices;
};






#endif