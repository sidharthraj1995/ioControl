/******************************************************
 * WE DEFINE ALL THE HARDWARE RELATED PROPERTIES HERE *
 *     PULL INFORMATION RELATED TO THE CONTROLLER     *
 *            CHECK FOR SENSORS, PIN, TYPE            *
 *         INIT THE CONTROLLER AND THE SENSOR         *
 ******************************************************/

#include "Hardware.h"


CController::CController(/* args */)
{
    _qtyController = 0;
    _qtySensor = 0;
    bInited = false;
    bValidated = false;
}

CController::~CController()
{
    Serial.println("Controller Destroyed!! Congrats - Not defined yet");
}

bool CController::Init() {
    bInited = true;
    return true;
}

bool CController::Register(String ctlName, controllerType ctlType, uint16_t sensors) {
    if(Init()) {
        for (int i = 0; i < MAX_CTL_QTY; i++)
        {
            if (!(i == CTL_NONE)) {

            }
        }
        
    }
}


//------------- Sensor Definition below ------------------//
CSensor::CSensor(/* args */)
{
}

CSensor::~CSensor()
{
}

