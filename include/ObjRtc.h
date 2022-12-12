#ifndef A_OBJ_RTC_h
#define A_OBJ_RTC_h

#include "ControlIO.h"
#include "enum.h"

/*************************************************************/

typedef struct {
  bool                 bRegistered;
  uint8_t              idxIO;
  SYS_STATE            currentState;
  PIN_MODE             pinMode;     // Specific the mode type
  IO_TYPE              ioType;        // Type: Input or output
  NODE_TYPE            nodeType;    // Digital or Analog
} OBJ_DEVICEIO_STATUS;

typedef struct {
  DEVICE_LIST          devEnum;
  char                 Name[MAX_NAME_LENGTH];      // Name of the sensor
  int8_t               pin;                         // GPIO pin number
  PORT_TYPE            portType;
  SCAN_RATE            scanRate;
  OBJ_DEVICEIO_STATUS  statusIO;                   // OBJ to monitor status
} OBJ_DEVICES;

/* Control IO OBJ */
typedef struct {
  bool                 bInUse;                     // flag to check if the IO is in use
  bool                 bisHardware;                // flag to check if the module is hardware
  CTL_LIST             masterCTL;                 // Connected Controller
  OBJ_DEVICES          connectedDev[DEVICE_MAX_ASIZE - 1];  
} OBJ_DEVICEIO;




/*************************************************************/

typedef struct {
  LOG_STATE             logging;
  bool                  bNetwork;    // Network
  bool                  bComm;       // PubSub comm
  bool                  bHasHAT;     // Connected HAT
  bool                  bHasIPower;  // Intelligent power supply with feedback
} OBJ_CONTROLLER_SETTING;

typedef struct {
  bool                      bRegistered;
  uint8_t                   idxCTL;
  uint8_t                   connectedDev;
  SYS_STATE                 statusCTL;
  NET_STATE                 netCTL;
} OBJ_CONTROLLER_STATUS;

/* Controller OBJ */
typedef struct {
  bool                        bInUse;
  char                        Name[MAX_NAME_LENGTH];  // Name of the Controller
  CONTROLLER_TYPE             Type;                   // Type of Controller
  uint16_t                    PinsUsed;               // Init: Total Number of GPIO pins used, set to -1 for no sensor
  OBJ_CONTROLLER_STATUS       StatusCTL;
  OBJ_CONTROLLER_SETTING      SettingCTL;
  OBJ_DEVICEIO                DeviceIO;
} OBJ_CONTROLLER;

/*************************************************************/

struct OBJ_PROJECT_INFO {
  char                   ProjectName[MAX_NAME_LENGTH];
  char                   Author[MAX_NAME_LENGTH];
  char                   Framework[MAX_NAME_LENGTH];
  // uint16_t               FrameworkVersion;
};

/* System OBJ */
struct OBJ_SYSTEM {
  char                    Name[MAX_NAME_LENGTH];
  char                    InitDay0[MAX_DATE_LENGTH];
  OBJ_PROJECT_INFO        Info;
  OBJ_CONTROLLER          Controller;
};

/*************************************************************/

#endif