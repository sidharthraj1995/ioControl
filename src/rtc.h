#ifndef __RTC_H_Q5J47YXKDIMF__
#define __RTC_H_Q5J47YXKDIMF__



#include "Global.h"


static OBJ_SYSTEM         *pSys;
static OBJ_CONTROLLER     *pCtl;
static OBJ_DEVICEIO       *pDev;



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
    bool                bRegistered;
    bool                bInit;

public:
    CController();
    ~CController();
    bool Init();
    void Register();


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
class CDeviceIO: public CController
{
private:
    
protected:
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
