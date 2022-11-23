#ifndef A_OBJ_RTC_h
#define A_OBJ_RTC_h

#include "enum.h"
#include "ControlIO.h"

/*************************
 *   CUSTOM STRUCTURES   *
 * TO DEFINE CONTROLLERS *
 *      AND SENSORS      *
 *************************/


/* System OBJ */
typedef struct {
    char                Name[MAX_NAME_LENGTH];
    OBJ_CONTROLLER      Controller[MAX_QTY_CONTROLLER];
    OBJ_DEVICEIO        DeviceIO[MAX_QTY_SENSOR];

} OBJ_SYSTEM;


typedef struct {
    char                Name[MAX_NAME_LENGTH];
    char                Author[MAX_NAME_LENGTH];
} OBJ_PROJECT_INFO;




/* Controller OBJ */
typedef struct
{
    bool                    bInUse;
    char                    Name[MAX_NAME_LENGTH]; // Name of the Controller
    CONTROLLER_TYPE         Type;    // Type of Controller
    uint16_t                pinsUsed;       // Init: Total Number of GPIO pins used, set to -1 for no sensors
    OBJ_SETTING_CONTROLLER  settingCTL;
} OBJ_CONTROLLER;

typedef struct
{
    uint16_t        idxCTL;
    LOG_STATE       logging;
    bool            bHasHAT;                // Connected HAT
    bool            bHasIPower;             // Intelligent power supply with feedback
} OBJ_SETTING_CONTROLLER;








/* Control IO OBJ */
typedef struct
{
    bool                    bInUse;                  // flag to check if the IO is in use
    bool                    bisHardware;            // flag to check if the module is hardware
    char                    Name[MAX_NAME_LENGTH];  // Name of the sensor
    OBJ_STATUS_DEVICEIO     statusIO;               // OBJ to monitor status
    OBJ_SETTING_DEVICEIO    ioSetting;              // OBJ to define module settings
} OBJ_DEVICEIO;

typedef struct {
    PORT_TYPE       portType;
    PIN_MODE        pinMode;                // Specific the mode type
    SCAN_RATE       scanRate;               // Device scan rate
    CTL_LIST        masterCTL;              // Connected Controller
    byte            PIN;                    // Connected PIN
} OBJ_SETTING_DEVICEIO;

typedef struct
{
    uint16_t        idxIO;
    IO_STATE        currentState;
    IO_TYPE         ioType;             // Type: Input or output
    NODE_TYPE       SignalType;             // Digital or Analog
} OBJ_STATUS_DEVICEIO;





typedef struct {

} OBJ_SYSTEM;

typedef struct {

} OBJ_MODULE;





#endif