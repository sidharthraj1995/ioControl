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
CController::CController() {
  bInit = false;
  bRegistered = false;
}

CController::~CController() {
  Serial.println("CController() deconstructor called! Well done!");
}

bool CController::Init() { 
  bInit = true; 
  // pCtl = &pSys->Controller;     // try memcpy?
  return 1;
}

bool CController::Register() {
  return 0;
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