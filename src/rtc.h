#ifndef __RTC_H_Q5J47YXKDIMF__
#define __RTC_H_Q5J47YXKDIMF__

// #include <Arduino.h>
// #include "enum.h"
// #include "ControlIO.h"
// #include "ObjRtc.h"


#include "Global.h"

// GLOBAL CController         cCtl;
// GLOBAL CDeviceIO           cDev[MAX_QTY_SENSOR];


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

protected:
    OBJ_SYSTEM          *pSys;
    OBJ_CONTROLLER      *pCtl;
    OBJ_DEVICEIO        *pDev;

    int            totalCtl;


public:
    CSystem();
    ~CSystem();
    void Init(OBJ_SYSTEM Sys);
    bool Register();

    // virtual void Register() = 0;

};


//--------------------------------------------------------------//

class CController : public CSystem
{
private:
    
protected:
    OBJ_CONTROLLER      *pmCtl;
    bool                bRegistered;
    bool                bInit;

public:
    CController();
    ~CController();
    bool Init();
    void Register();


};

//--------------------------------------------------------------//

/* This is where you define your Devices
and IOs.
Derived class */ 
class CDeviceIO: public CController
{
private:
    
protected:
    OBJ_DEVICEIO    *pmDev;
    bool            bInit;
    bool            bRegister;

public:
    CDeviceIO();
    ~CDeviceIO();
    bool Init();
    bool Register();
    

    uint16_t    QtyDevices;
};






#endif  // __RTC_H_Q5J47YXKDIMF__
