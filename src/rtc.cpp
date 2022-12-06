#include "rtc.h"


static OBJ_SYSTEM         *pSys;
static OBJ_CONTROLLER     *pCtl;
static OBJ_DEVICEIO       *pDev;




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

bool CController::Register() {
    if (!pCtl->bInUse  && pCtl->StatusCTL.statusCTL != STS_INIT )
    {
        Serial.println("You moron, CTL is NOT in use! Fix your shit!");
        return 0;
    }
    // totalCtl++;             // increment controller index
    pCtl->StatusCTL.idxCTL = totalCtl++;
    pCtl->StatusCTL.statusCTL = STS_EN;
    Serial.printf("New Controller Registered, NAME: %s , Index: %d \n", pCtl->Name, pCtl->StatusCTL.idxCTL);
    bRegistered = true;
    return bRegistered;

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

bool CDeviceIO::AddIO(OBJ_DEVICEIO *DevIO) {
    return 0;
}

//------------- DeviceIO Definition END ------------------//





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
    Serial.println("\n");
    Serial.println('\n');
    Serial.println("New system Init() started!");
    Serial.println('\n');

    // Print all Project specific data
    Serial.printf("Name: %s \n", pSys->Name);
    Serial.printf("InitDate: %s \n", pSys->InitDay0);
    Serial.printf("Project Name: %s \n", pSys->Info.ProjectName);
    Serial.printf("Framework version: %s \n", pSys->Info.Framework);
    Serial.printf("Author Name: %s \n", pSys->Info.Author);
    Serial.println('\n');

    pCtl = &pSys->Controller;           // pass Controller's addr to static pointer to Ctl, defined 
    pCtl->StatusCTL.statusCTL = STS_INIT;       // set controller state to INIT, will be checked by CController

    Serial.println("\n");
    Serial.println('\n');
    Serial.println("Congrats, new system Init() successful!");
    Serial.println('\n');
    Serial.println('\n');


    // TODO  Call CController::Register() below
    // Call derived class method inside base class
    CController::Register();
}

//------------- System Definition END ------------------------//




