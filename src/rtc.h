#ifndef __RTC_H_Q5J47YXKDIMF__
#define __RTC_H_Q5J47YXKDIMF__

#include <Arduino.h>
#include "enum.h"
#include "ControlIO.h"
// #include "ObjRtc.h"


#include "DefRtc.h"


#define GLOBAL extern

GLOBAL OBJ_SYSTEM *pSys;

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
    OBJ_SYSTEM *pSys;

public:
    CSystem();
    ~CSystem();
    // void Init(OBJ_SYSTEM sys);
    void Init();
    void Register();

};


#endif  // __RTC_H_Q5J47YXKDIMF__
