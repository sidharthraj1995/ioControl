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

void CSystem::Init(OBJ_SYSTEM Sys) {
    bInit = true;
    pSys = &Sys;
    // memcpy(pSys, &Sys, sizeof(OBJ_SYSTEM));
    Serial.flush();
    Serial.println('\n');
    Serial.println('\n');
    Serial.println("Congrats, new system Init() successful!");
    Serial.println('\n');
    Serial.println('\n');
    Serial.printf("Name: %s \n", pSys->Name);
    Serial.printf("InitDate: %s \n", pSys->InitDay0);
    Serial.printf("Project Name: %s", pSys->Info.ProjectName);
    Serial.printf("Framework version: %s \n", pSys->Info.Framework);
    Serial.printf("Author Name: %s \n", pSys->Info.Author);
}

void CSystem::Register() {

}

//------------- System Definition END ------------------------//
