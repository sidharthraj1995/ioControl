#include "rtc.h"



//------------- System Definition START ------------------//

/* CController Class Constructor
Sets all values to default */
CSystem::CSystem() {
    bInit = false;
    bRegistered = false;
}

CSystem::~CSystem() {
    bInit = false;
    bRegistered = false;
    delete pSys;
    Serial.println("Congrats, deconstructor called!!");
}

void CSystem::Init() {
    bInit = true;
    // pSys = &Obj_sys;
    memcpy(pSys, &Obj_sys, sizeof(OBJ_SYSTEM));
    Serial.println("Congrats, new system Init() successful!");
    Serial.printf("Name: %c\n", pSys->Name);
    Serial.printf("Framework version: %d\n", pSys->Info.FrameworkVersion);
}

void CSystem::Register() {

}

//------------- System Definition END ------------------------//
