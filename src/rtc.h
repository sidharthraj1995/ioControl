#ifndef __RTC_H_Q5J47YXKDIMF__
#define __RTC_H_Q5J47YXKDIMF__



#include "Global.h"




/***************************************************
 *                CONTROLLER CLASS                 *
 *          THIS IS THE MASTER CLASS THAT          *
 * CALLS ALL THE OTHER FOUNDATION CLASS/METHODS TO *
 *                 INIT THE SYSTEM                 *
 ***************************************************/
class CController
{
private:
    
protected:
    bool                bRegistered;
    bool                bInit;
    int                 totalCtl;

public:
    CController();
    ~CController();
    bool Init(OBJ_CONTROLLER *Ctl);
    bool Preregister(OBJ_CONTROLLER_STATUS *pCtlStatus);         // set all STATUS values to default
    bool Register(OBJ_CONTROLLER_SETTING *pCtlSetting);
    
    // bool AddIO();
    // virtual bool AddIO(OBJ_DEVICEIO *DevIO) = 0;
};


/*================== CDeviceIO =================*/
/* This is where you define your Devices
and IOs.
Derived class */ 
class CDeviceIO : public CController
{
private:
    bool SetPin(int8_t pin, PIN_MODE mode);
    bool ReadPin(int8_t pin);
protected:
    bool            bInit;
    bool            bRegister;
    uint8_t         QtyDevices;

public:
    CDeviceIO();
    ~CDeviceIO();
    // void Init(OBJ_DEVICES *pDev);
    bool PreRegister(OBJ_DEVICEIO_STATUS *pDevStatus);
    bool Register(OBJ_DEVICES *pDev);

    bool AddIO(OBJ_DEVICES *devIO);
    bool ReadIO(OBJ_DEVICES *devIO);
};


/*================== CSystem =================*/
/* Class System 
Inits and sets project info */
class CSystem : public CController
{
private:
    bool bInit;
    bool bRegistered;

protected:

public:
    CSystem();
    ~CSystem();
    void Init(OBJ_SYSTEM Sys);
    bool Register(OBJ_SYSTEM *Sys);
    // bool PreRegister();

};




#endif  // __RTC_H_Q5J47YXKDIMF__
