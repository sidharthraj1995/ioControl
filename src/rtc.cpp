#include "rtc.h"


static OBJ_SYSTEM         *ptrSys;
static OBJ_CONTROLLER     *ptrCtl;
static OBJ_DEVICEIO       *ptrDev;


/* Concept is clear - 
* You have Init(), PreRegister() Register(),
* Constructor() - Sets class flags
* Init()        - Passes main OBJ pointer to internal ptr
* PreRegister() - Sets OBJ status flags
* Register()    - Sets/runs the internal logic, depends on the class
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
/**
 * CController 
 * 
 * @param  {OBJ_CONTROLLER &} Ctl : 
 * @return {bool}                 : 
 */
bool CController::Init(OBJ_CONTROLLER *Ctl) { 
    bInit = true;
    // CController::Preregister();
    // ptrCtl = &pSys->Controller;           // pass Controller's addr to static pointer to Ctl, defined 
    // ptrCtl->StatusCTL.statusCTL = STS_INIT;       // set controller state to INIT, will be checked by CController
    return bInit;
}
/**
 * CController 
 * 
 * @param  {OBJ_CONTROLLER_STATUS*} pCtlStatus : 
 * @return {bool}                              : 
 */
bool CController::Preregister(OBJ_CONTROLLER_STATUS *pCtlStatus) {
    if (!bInit) {
        Serial.println(F("Controller Init() pending, terminating Controller PreRegistration!"));
        return bInit;
    }
    pCtlStatus->bRegistered  = false;
    pCtlStatus->idxCTL       = -1;
    pCtlStatus->connectedDev = -1;
    pCtlStatus->statusCTL    = STS_DEFAULT;
    pCtlStatus->netCTL       = NET_STS_DEFAULT;
    Serial.println("Controller PreRegistration() successful. All status flags set to default");
    return true;
}
/**
 * CController 
 * 
 * @param  {OBJ_CONTROLLER_SETTING*} pCtlSetting : 
 * @return {bool}                                : 
 */
bool CController::Register(OBJ_CONTROLLER_SETTING *pCtlSetting) {
    if (!ptrCtl->bInUse  && ptrCtl->StatusCTL.statusCTL != STS_INIT )
    {
        Serial.println("You moron, CTL is NOT in use! Fix your shit!");
        return false;
    }
    // bRegistered                 = true; 
    ptrCtl->StatusCTL.idxCTL    = totalCtl++;
    ptrCtl->StatusCTL.statusCTL = STS_EN;
    // ptrDev = &ptrCtl->DeviceIO;
    Serial.printf("New Controller Registered,\n NAME: %s ,\n Index: %d \n", ptrCtl->Name, ptrCtl->StatusCTL.idxCTL);
    return (bRegistered = true);
}

//------------- Controller  END ------------------//





//------------- DeviceIO  START ------------------//
/* CSensor Constructor
Sets various values to default */
/**
 * CDeviceIO::CDeviceIO 
 * 
 */
CDeviceIO::CDeviceIO() {
    bInit      = false;
    bRegister  = false;
    QtyDevices = -1;
}
/**
 * CDeviceIO::~CDeviceIO 
 * 
 */
CDeviceIO::~CDeviceIO() {
    delete ptrDev;
    Serial.println("CDeviceIO() deconstructor called, enjoy!");
}


// void CDeviceIO::Init(OBJ_DEVICES *pDev) {
//     Serial.println(F("Device Init() successful."));
// }


/**
 * CDeviceIO 
 * 
 * @param  {OBJ_DEVICEIO_STATUS*} pDevStatus : 
 * @return {bool}                            : 
 */
bool CDeviceIO::PreRegister(OBJ_DEVICEIO_STATUS *pDevStatus) {
    if (!bInit)
    {
        Serial.println(F("Device Init() pending, terminating Device PreRegisteration!"));
        return false;
    }
    pDevStatus->bRegistered  = false;
    pDevStatus->idxIO        = -1;
    pDevStatus->currentState = STS_DEFAULT;
    return true;
}

bool CDeviceIO::Register(OBJ_DEVICES *pDev) {
    
    return false;
}

bool CDeviceIO::SetPin(int8_t pin, PIN_MODE mode) {
    switch (mode)
    {
    case PIN_MODE_OUTPUT:
        pinMode(pin, OUTPUT);
        break;
    
    case PIN_MODE_INPUT:
        pinMode(pin, INPUT);
        break;
    
    case PIN_MODE_INPUT_PULLDOWN:
        pinMode(pin, INPUT_PULLDOWN_16);
        break;
    
    case PIN_MODE_INPUT_PULLUP:
        pinMode(pin, INPUT_PULLUP);
        break;
    
    default:
        Serial.println(F("Unable to AddIO(), checck your shit!!"));
        return false;
    }
    return true;
}

bool CDeviceIO::AddIO(OBJ_DEVICES *devIO) {
    if(!bRegister) {
        Serial.println(F("Cannot add IO since class is not registered!"));
        return false;
    }
    devIO->statusIO.idxIO = ++QtyDevices;
    devIO->statusIO.bRegistered = CDeviceIO::SetPin(devIO->pin, devIO->pinMode);
    Serial.printf("New IO registered, Name: %s | Idx: %d", devIO->Name, devIO->statusIO.idxIO);
    return true;
}

bool CDeviceIO::ReadPin(int8_t pin) {
    return (digitalRead(pin));
}

bool CDeviceIO::ReadIO(OBJ_DEVICES *devIO) {
    if (!(devIO->statusIO.bRegistered))
    {
        Serial.println(F("Cannot read IO since the device is not registered!"));
        return false;
    }
    // devIO->statusIO.currentState = CDeviceIO::ReadPin(devIO->pin);
    if (!(CDeviceIO::ReadPin(devIO->pin)))
        devIO->statusIO.currentState = STS_OFF;
    else
        devIO->statusIO.currentState = STS_ON;

    Serial.printf("IO scan successful, Name: %s  |  State: %s", devIO->Name, devIO->statusIO.currentState);
    return true;
}

//------------- DeviceIO  END ------------------//





//------------- System  START ------------------//

/* CController Class Constructor
Sets all values to default */
/**
 * CSystem::CSystem 
 * 
 */
CSystem::CSystem() {
    bInit = false;
    bRegistered = false;

    totalCtl = 0;
}
/**
 * CSystem::~CSystem 
 * 
 */
CSystem::~CSystem() {
    bInit = false;
    bRegistered = false;
    delete ptrSys;
    Serial.println("Congrats, deconstructor called!!");
}
/**
 * CSystem 
 * 
 * @param  {OBJ_SYSTEM} Sys : 
 */
void CSystem::Init(OBJ_SYSTEM Sys) {
    bInit = true;
    ptrSys = &Sys;
    // memcpy(pSys, &Sys, sizeof(OBJ_SYSTEM));
    Serial.println(F("\n"));
    Serial.println(F("\n"));
    Serial.println(F("New system Init() started!"));
    Serial.println(F("\n"));


    // ptrCtl = &ptrSys->Controller;           // pass Controller's addr to static pointer to Ctl, defined 
    // ptrCtl->StatusCTL.statusCTL = STS_INIT;       // set controller state to INIT, will be checked by CController

    Serial.println("\n");
    Serial.println('\n');
    Serial.println("Congrats, new system Init() successful!");
    Serial.println('\n');
    Serial.println('\n');
}


/**
 * CSystem 
 * 
 * @return {bool}  : 
 */
bool CSystem::Register() {
    // Print all Project specific data
    Serial.printf("Name: %s \n", ptrSys->Name);
    Serial.printf("InitDate: %s \n", ptrSys->InitDay0);
    Serial.printf("Project Name: %s \n", ptrSys->Info.ProjectName);
    Serial.printf("Framework version: %s \n", ptrSys->Info.Framework);
    Serial.printf("Author Name: %s \n", ptrSys->Info.Author);
    Serial.println('\n');
    bRegistered = true;
    return bRegistered;
}


// bool CSystem::PreRegister() {
//     // Print all Project specific data
//     Serial.printf("Name: %s \n", ptrSys->Name);
//     Serial.printf("InitDate: %s \n", ptrSys->InitDay0);
//     Serial.printf("Project Name: %s \n", ptrSys->Info.ProjectName);
//     Serial.printf("Framework version: %s \n", ptrSys->Info.Framework);
//     Serial.printf("Author Name: %s \n", ptrSys->Info.Author);
//     Serial.println('\n');
//     return true;
// }

//------------- System  END ------------------------//




