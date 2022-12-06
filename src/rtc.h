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
    bool Register();
    virtual bool AddIO(OBJ_DEVICEIO *DevIO) const;
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
    virtual bool AddIO(OBJ_DEVICEIO *DevIO);

public:
    CDeviceIO();
    ~CDeviceIO();
    // bool Register();

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

    // virtual void Register() const = 0;

};




#endif  // __RTC_H_Q5J47YXKDIMF__
