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
    if (ptrCtl->bInUse || ptrCtl->StatusCTL.statusCTL == STS_INIT) {
        Serial.println("Error: Controller is already in use.");
        return false;
    }
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


/**
 * CDeviceIO 
 * 
 * @param  {OBJ_DEVICEIO_STATUS*} pDevStatus : 
 * @return {bool}                            : 
 */
bool CDeviceIO::PreRegister(OBJ_DEVICEIO_STATUS *pDevStatus) {
    if (!bInit)
    {
        Serial.println(F("Error: Device Init() pending, terminating Device PreRegisteration!"));
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
    if (devIO == nullptr)
    {
        Serial.println(F("Error: Invalid input"));
        return false;
    }
    if(!bRegister) {
        Serial.println(F("Error: Class not registered"));
        return false;
    }
    if(!(CDeviceIO::SetPin(devIO->pin, devIO->pinMode))) {
        return false;
    }
    devIO->statusIO.idxIO = ++QtyDevices;
    devIO->statusIO.bRegistered = true;
    Serial.printf("New IO registered, Name: %s | Idx: %d", devIO->Name, devIO->statusIO.idxIO);
    return true;
}



bool CDeviceIO::ReadPin(int8_t pin) {
    if(pin < 0 || pin > NUM_GPIO_PINS) {
        Serial.println(F("Error: Invalid pin number"));
        return false;
    }
    pinMode(pin, INPUT);
    int8_t pinState = digitalRead(pin);
    if (pinState == -1)
    {
        Serial.println(F("Error: Failed to read pin"));
        return false;
    }
    return (pinState = HIGH);
}

bool CDeviceIO::ReadIO(OBJ_DEVICES *devIO) {
    if (!devIO->statusIO.bRegistered) {
        Serial.println(F("Error: Device is not registered"));
        return false;
    }
    bool pinState = CDeviceIO::ReadPin(devIO->pin);
    if (pinState == -1) {
        Serial.println(F("Error: Failed to read pin"));
        return false;
    }
    devIO->statusIO.currentState = (pinState) ? STS_ON : STS_OFF;

    Serial.printf("IO scan successful, Name: %s  |  State: %s\n", devIO->Name, (devIO->statusIO.currentState == STS_ON) ? "ON" : "OFF");
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
    Serial.println(F("\n"));
    Serial.println(F("\n"));
    Serial.println(F("New system Init() started!"));
    Serial.println(F("\n"));



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
bool CSystem::Register(OBJ_SYSTEM *Sys) {
    // Print all Project specific data
    bRegistered = true;
    Serial.printf("Name: %s \n", Sys->Name);
    Serial.printf("InitDate: %s \n", Sys->InitDay0);
    Serial.printf("Project Name: %s \n", Sys->Info.ProjectName);
    Serial.printf("Framework version: %s \n", Sys->Info.Framework);
    Serial.printf("Author Name: %s \n", Sys->Info.Author);
    Serial.println('\n');
    return bRegistered;
}



//------------- System  END ------------------------//




