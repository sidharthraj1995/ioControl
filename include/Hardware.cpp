/***************************************************
 * DEFINE ALL THE HARDWARE RELATED PROPERTIES HERE *
 *   PULL INFORMATION RELATED TO THE CONTROLLER    *
 *          CHECK FOR SENSORS, PIN, TYPE           *
 *       INIT THE CONTROLLER AND THE SENSOR        *
 ***************************************************/

#include "Hardware.h"


//------------- Controller Definition START ------------------//

/* CController Class Constructor 
Sets all values to default */
CController::CController()
{
    _idxController = -1;
    bInited = false;
    bRegistered = false;
}

/* CController Deconstructor */
CController::~CController()
{
    Serial.printf("Controller: %s Destroyed!! Congrats - Not defined yet\n", ctlName);
}

/* CController Init 
Sets init flag for Register logic to process */
bool CController::Init() {
    bInited = true;
    return true;
}

/* CController Register 
Copies all the required parameters for further processing */
bool CController::Register(OBJ_CONTROLLER* Controller) {
    if(!bInited) {
        Serial.printf("Controller: %s cannot be registered, pls Init controller.\n", ctlName);
        return false;
    } else {
        strcpy(ctlName, Controller->Name);
        _type = Controller->Type;
        _totalPinsUsed = Controller->pinsUsed;
        bRegistered = true;
        return true;
    }
}
//------------- Controller Definition END ------------------//


//------------- Sensor Definition START ------------------//
/* CSensor Constructor 
Sets various values to default */
CSensor::CSensor()
{
    _sensorPin = -1;
    _signalType = NODE_DEFAULT;
    _sensorType = TYPE_DEFAULT;
    _senCTL = CTL_LIST_DEFAULT;
    bInited = false;
    bRegistered = false;
}

/* CSensor Deconstructor */
CSensor::~CSensor()
{
    Serial.printf("Sensor: %s Destroyed!! Congrats you did it!\n", senName);
}

/* CSensor Init 
Sets init flag for Register logic to process */
bool CSensor::Init() {
    bInited = true;
    return true;
}


/* CSensor Register 
Sets all required values after checking for Init */
bool CSensor::Register(OBJ_SENSOR* Sensor) {
    if(!bInited) {
        Serial.printf("Sensor: %s cannot be registered, check for Init!", Sensor->Name);
        return false;
    } else {
        _sensorPin = Sensor->PIN;
        _signalType = Sensor->SignalType;
        _sensorType = Sensor ->SensorType;
        _senCTL = Sensor->masterCTL;

        bRegistered = true;
        return true;
    }
}

bool CSensor::PostRegister() {
    if(_senCTL != CTL_LIST_DEFAULT && bRegistered) {
        //todo  Do some shit here, call setMode and validate 
    }
}


/* CSensor setMode 
Checks for type of sensor and sets the Pin Mode accordingly
INPUT or OUTPUT */
bool CSensor::setMode() {
    switch (_sensorType)
    {
    case TYPE_INPUT:
        pinMode(_sensorPin, INPUT);
        Serial.printf("Sensor: %s, Mode set to INPUT", senName);
        break;
    case TYPE_OUTPUT:
        pinMode(_sensorPin, OUTPUT);
        Serial.printf("Sensor: %s, Mode set to OUTPUT", senName);

    default:
        Serial.println("Eat shit, default type is BAD!!");
        break;
    }
}


//------------- Sensor Definition END ------------------//