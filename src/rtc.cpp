#include "rtc.h"


static OBJ_SYSTEM         *pSys;
static OBJ_CONTROLLER     *pCtl;
static OBJ_DEVICEIO       *pDev;


/* Concept is clear - 
* You have Init(), Register(),
* Init() - Takes the address of the main OBJ
* Register() - 
*/



//------------- Controller  START ------------------//

/* CController Class Constructor
Sets all values to default */
CController::CController() {
    bInit = false;
    bRegistered = false;
}

CController::~CController() {
    delete pCtl;
    Serial.println("CController() deconstructor called! Well done!");
}

bool CController::Init(OBJ_CONTROLLER &Ctl) { 
    pCtl = &Ctl;

    // pCtl = &pSys->Controller;           // pass Controller's addr to static pointer to Ctl, defined 
    // pCtl->StatusCTL.statusCTL = STS_INIT;       // set controller state to INIT, will be checked by CController
    return bInit;
}

bool CController::Preregister() {
    if (!bInit) {
        Serial.println(F("Controller Init() pending!"));
        return false;
    }
    bInit = true;
    pCtl->StatusCTL.bRegistered  = true;
    pCtl->StatusCTL.connectedDev = 0;
    pCtl->StatusCTL.idxCTL       = 0;
    pCtl->StatusCTL.statusCTL    = STS_INIT;
    pCtl->StatusCTL.netCTL       = NET_STS_DISABLED;
    Serial.println("Controller Init() successful.");
    return true;
}

bool CController::Register() {
    if (!pCtl->bInUse  && pCtl->StatusCTL.statusCTL != STS_INIT )
    {
        Serial.println("You moron, CTL is NOT in use! Fix your shit!");
        return false;
    }
    bRegistered = true;
    pCtl->StatusCTL.idxCTL = totalCtl++;
    pCtl->StatusCTL.statusCTL = STS_EN;
    // pDev = &pCtl->DeviceIO;
    Serial.printf("New Controller Registered, NAME: %s , Index: %d \n", pCtl->Name, pCtl->StatusCTL.idxCTL);
    return bRegistered;
}

//------------- Controller  END ------------------//





//------------- DeviceIO  START ------------------//
/* CSensor Constructor
Sets various values to default */

CDeviceIO::CDeviceIO() {
}

CDeviceIO::~CDeviceIO() {
    delete pDev;
    Serial.println("CDeviceIO() deconstructor called, enjoy!");
}

void CDeviceIO::Init() {
    pDev->statusIO.bRegistered      = false;
    pDev->statusIO.idxIO            = 0;
    pDev->statusIO.portType         = PORT_TYPE_DEFAULT;
    pDev->statusIO.ioType           = TYPE_DEFAULT;
    pDev->statusIO.SignalType       = NODE_TYPE_DEFAULT;
    Serial.println(F("Device Init() successful."));
}

bool CDeviceIO::AddIO(OBJ_DEVICEIO *DevIO) {
    if(DevIO->bInUse)
    return 0;
}

//------------- DeviceIO  END ------------------//





//------------- System  START ------------------//

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

    
    // convert below to CController Init() method
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

//------------- System  END ------------------------//




