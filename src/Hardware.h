/****************************
 * GENERAL LIBRARY TO INIT  *
 * AND PLAY WITH IO SENSORS *
 ****************************/
#ifndef A_HARDWARE_h
#define A_HARDWARE_h

#include "rtc.h"

/* How do you wanna approach this? have a master class and then derive controller
and deviceIO CLASS out of it?
how do you want to handle deviceIO  ---->> it needs to be forked into II and IO

what is shared between these class? why use inheritence?
*/


class CController : public CSystem
{
private:
    
protected:
    OBJ_CONTROLLER* pCtl;

public:
    CController();
    ~CController();
    bool Init();
    bool Register();


    bool bInit;
    bool bRegistered;
};


/* This is where you define your Devices
and IOs.
Derived class */ 
class CDeviceIO: public CController
{
private:
    bool bInit;
    bool bRegister;
    
protected:
    OBJ_DEVICEIO *pDev;

public:
    CDeviceIO();
    ~CDeviceIO();
    bool Init();
    bool Register();
    

    uint16_t    QtyDevices;
};






#endif