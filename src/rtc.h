#ifndef __RTC_H_Q5J47YXKDIMF__
#define __RTC_H_Q5J47YXKDIMF__



#include "Global.h"




/****************************************
 *           CONTROLLER CLASS           *
 *    THIS IS THE MASTER CLASS THAT     *
 * CALLS ALL THE OTHER CLASS/METHODS TO *
 *           INIT THE SYSTEM            *
 ****************************************/
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
    bool Init();
    bool Preregister();         // set all STATUS values to default
    bool Register();
    bool AddIO();
    // virtual bool AddIO(OBJ_DEVICEIO *DevIO) = 0;
};

//--------------------------------------------------------------//
/************************************************
 *     DONT THINK I NEED THIS SHIT ANYMORE,     *
 * SHOULD GO AHEAD AND MERGE IT WITH CONTROLLER *
 *                    CLASS                     *
 ************************************************/

/* This is where you define your Devices
and IOs.
Derived class */ 
class CDeviceIO
{
private:
    
protected:
    bool            bRegister;

public:
    CDeviceIO();
    ~CDeviceIO();
    void Init();
    // bool Register();
    bool AddIO(OBJ_DEVICEIO *DevIO);

    uint16_t    QtyDevices;
};




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
    // bool Register();


};




#endif  // __RTC_H_Q5J47YXKDIMF__
