/***************************************************
 * DEFINE ALL THE HARDWARE RELATED PROPERTIES HERE *
 *   PULL INFORMATION RELATED TO THE CONTROLLER    *
 *          CHECK FOR SENSORS, PIN, TYPE           *
 *       INIT THE CONTROLLER AND THE SENSOR        *
 ***************************************************/

#include "Hardware.h"


//------------- System Definition START ------------------//

/* CController Class Constructor 
Sets all values to default */
CSystem::CSystem()
{
    bInit = false;
    bRegistered = false;
}

CSystem::~CSystem()
{
    Serial.println("Congrats you messed up and called the deconstructor!!");
}

bool CSystem::Init() {
    bInit = true;
    Serial.println("Time to Init() your system class, this is required for controller and devices attached to it!");
}

bool CSystem::Register() {
}

//------------- System Definition END ------------------//



//------------- Controller Definition START ------------------//

/* CController Class Constructor 
Sets all values to default */
CController::CController()
{
    bInit = false;
    bRegistered = false;
}

CController::~CController()
{
    Serial.println("CController() deconstructor called! Well done!");
}

bool CController::Init(OBJ_CONTROLLER* ctl) {
    pCtl = *ctl;
    
    bInit = true;
}

bool CController::Register() {

}

//------------- Controller Definition END ------------------//







//------------- DeviceIO Definition START ------------------//
/* CSensor Constructor 
Sets various values to default */

CDeviceIO::CDeviceIO()
{
    bInit = false;
    bRegister = false;

    QtyDevices = -1;        // THINK! what? why?
}

CDeviceIO::~CDeviceIO()
{
    Serial.println("CDeviceIO() deconstructor called, enjoy!");
}






//------------- DeviceIO Definition END ------------------//