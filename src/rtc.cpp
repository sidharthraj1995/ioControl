#include "rtc.h"



//------------- System Definition START ------------------//

/* CController Class Constructor
Sets all values to default */
CSystem::CSystem() {
    bInit = false;
    bRegistered = false;

    totalCtl = 0;
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

    // Print all Project related data
    Serial.printf("Name: %s \n", pSys->Name);
    Serial.printf("InitDate: %s \n", pSys->InitDay0);
    Serial.printf("Project Name: %s \n", pSys->Info.ProjectName);
    Serial.printf("Framework version: %s \n", pSys->Info.Framework);
    Serial.printf("Author Name: %s \n", pSys->Info.Author);
    Serial.println('\n');
    // Serial.println('\n');

    pCtl = &pSys->Controller;
}


/*********************************************
 * THIS IS WHERE YOU REGISTER THE CONTROLLER *
 *********************************************/
bool CSystem::Register() {
    if (!bInit)
        return 0;

    // CSystem *cctl = new CController;
    // cctl->Register();
    // delete cctl;
    // bRegistered = true; 
    // return 1;

    if (!(pCtl->bInUse))
    {
        Serial.println("You moron, CTL is NOT in use! Fix your shit!");
        return 0;
    }
    // totalCtl++;             // increment controller index
    pCtl->StatusCTL.idxCTL = ++totalCtl;
    Serial.printf("Congrats, CTL: %s , Index: %d REGISTERED!\n", pCtl->Name, pCtl->StatusCTL.idxCTL);
    bRegistered = true;
    return bRegistered;
}

//------------- System Definition END ------------------------//




//------------- Controller Definition START ------------------//

/* CController Class Constructor
Sets all values to default */
CController::CController() {
    bInit = false;
    bRegistered = false;
}

CController::~CController() {
    Serial.println("CController() deconstructor called! Well done!");
}

bool CController::Init() { 
    bInit = true; 
    return 1;
}

void CController::Register() {
    if (!(pCtl->bInUse))
    {
        Serial.println("You moron, CTL is NOT in use! Fix your shit!");
        // return 0;
    }
    // totalCtl++;             // increment controller index
    pCtl->StatusCTL.idxCTL = ++totalCtl;
    Serial.printf("Congrats, CTL: %s , Index: %d REGISTERED!\n", pCtl->Name, pCtl->StatusCTL.idxCTL);
    bRegistered = true;
    // return bRegistered;

}

//------------- Controller Definition END ------------------//

//------------- DeviceIO Definition START ------------------//
/* CSensor Constructor
Sets various values to default */

CDeviceIO::CDeviceIO() {
    bInit = false;
    bRegister = false;

  QtyDevices = -1;  // THINK! what? why?
}

CDeviceIO::~CDeviceIO() {
    Serial.println("CDeviceIO() deconstructor called, enjoy!");
}

bool CDeviceIO::Init() {
    return 0;
}

//------------- DeviceIO Definition END ------------------//


