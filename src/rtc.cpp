#include "rtc.h"


static OBJ_SYSTEM         *ptrSys;
static OBJ_CONTROLLER     *ptrCtl;
static OBJ_DEVICEIO       *ptrDev;


/* Concept is clear - 
* You have Init(), PreRegister() Register(),
* Constructor() - Sets class flags
* Init() - Passes main OBJ pointer to internal ptr
* PreRegister() - Sets OBJ status flags
* Register() - Sets/runs the internal logic, depends on the class
*/



//------------- Controller  START ------------------//

/* CController Class Constructor
Sets all values to default */
CController::CController() {
    bInit = false;
    bRegistered = false;
}

CController::~CController() {
    delete ptrCtl;
    Serial.println("CController() deconstructor called! Well done!");
}

bool CController::Init(OBJ_CONTROLLER &Ctl) { 
    ptrCtl = &Ctl;

    // ptrCtl = &pSys->Controller;           // pass Controller's addr to static pointer to Ctl, defined 
    // ptrCtl->StatusCTL.statusCTL = STS_INIT;       // set controller state to INIT, will be checked by CController
    return bInit;
}

bool CController::Preregister() {
    if (!bInit) {
        Serial.println(F("Controller Init() pending!"));
        return false;
    }
    bInit = true;
    ptrCtl->StatusCTL.bRegistered  = true;
    ptrCtl->StatusCTL.connectedDev = 0;
    ptrCtl->StatusCTL.idxCTL       = 0;
    ptrCtl->StatusCTL.statusCTL    = STS_INIT;
    ptrCtl->StatusCTL.netCTL       = NET_STS_DISABLED;
    Serial.println("Controller Init() successful.");
    return true;
}

bool CController::Register() {
    if (!ptrCtl->bInUse  && ptrCtl->StatusCTL.statusCTL != STS_INIT )
    {
        Serial.println("You moron, CTL is NOT in use! Fix your shit!");
        return false;
    }
    bRegistered = true;
    ptrCtl->StatusCTL.idxCTL = totalCtl++;
    ptrCtl->StatusCTL.statusCTL = STS_EN;
    // ptrDev = &ptrCtl->DeviceIO;
    Serial.printf("New Controller Registered, NAME: %s , Index: %d \n", ptrCtl->Name, ptrCtl->StatusCTL.idxCTL);
    return bRegistered;
}

//------------- Controller  END ------------------//





//------------- DeviceIO  START ------------------//
/* CSensor Constructor
Sets various values to default */

CDeviceIO::CDeviceIO() {
}

CDeviceIO::~CDeviceIO() {
    delete ptrDev;
    Serial.println("CDeviceIO() deconstructor called, enjoy!");
}

void CDeviceIO::Init(OBJ_DEVICEIO *pDev) {
    ptrDev->statusIO.bRegistered      = false;
    ptrDev->statusIO.idxIO            = 0;
    ptrDev->statusIO.portType         = PORT_TYPE_DEFAULT;
    ptrDev->statusIO.ioType           = TYPE_DEFAULT;
    ptrDev->statusIO.SignalType       = NODE_TYPE_DEFAULT;
    Serial.println(F("Device Init() successful."));
}

bool CDeviceIO::AddIO(OBJ_DEVICEIO_SETTING *DevIO_Setting) {
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
    delete ptrSys;
    Serial.println("Congrats, deconstructor called!!");
}

void CSystem::Init(OBJ_SYSTEM Sys) {
    bInit = true;
    ptrSys = &Sys;
    // memcpy(pSys, &Sys, sizeof(OBJ_SYSTEM));
    Serial.println("\n");
    Serial.println('\n');
    Serial.println("New system Init() started!");
    Serial.println('\n');

    // Print all Project specific data
    Serial.printf("Name: %s \n", ptrSys->Name);
    Serial.printf("InitDate: %s \n", ptrSys->InitDay0);
    Serial.printf("Project Name: %s \n", ptrSys->Info.ProjectName);
    Serial.printf("Framework version: %s \n", ptrSys->Info.Framework);
    Serial.printf("Author Name: %s \n", ptrSys->Info.Author);
    Serial.println('\n');

    
    // convert below to CController Init() method
    ptrCtl = &ptrSys->Controller;           // pass Controller's addr to static pointer to Ctl, defined 
    ptrCtl->StatusCTL.statusCTL = STS_INIT;       // set controller state to INIT, will be checked by CController

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




