#ifndef A_OBJ_RTC_h
#define A_OBJ_RTC_h

#include "ControlIO.h"
#include "enum.h"

/*************************************************************/

typedef struct {
  PORT_TYPE            portType;
  PIN_MODE             pinMode;     // Specific the mode type
  SCAN_RATE            scanRate;    // Device scan rate
  CTL_LIST             masterCTL;   // Connected Controller
  byte                 PIN;         // Connected PIN
} OBJ_SETTING_DEVICEIO;

typedef struct {
  uint16_t             idxIO;
  SYS_STATE            currentState;
  IO_TYPE              ioType;        // Type: Input or output
  NODE_TYPE            SignalType;    // Digital or Analog
} OBJ_STATUS_DEVICEIO;

/* Control IO OBJ */
typedef struct {
  bool                 bInUse;                     // flag to check if the IO is in use
  bool                 bisHardware;                // flag to check if the module is hardware
  char                 Name[MAX_NAME_LENGTH];      // Name of the sensor
  OBJ_STATUS_DEVICEIO  statusIO;                   // OBJ to monitor status
  OBJ_SETTING_DEVICEIO ioSetting;                  // OBJ to define module settings
} OBJ_DEVICEIO;

/*************************************************************/

typedef struct {
  LOG_STATE             logging;
  bool                  bNetwork;    // Network
  bool                  bComm;       // PubSub comm
  bool                  bHasHAT;     // Connected HAT
  bool                  bHasIPower;  // Intelligent power supply with feedback
} OBJ_SETTING_CONTROLLER;

typedef struct {
  int                   idxCTL;
  SYS_STATE             statusCTL;
  NET_STATE             netCTL;
} OBJ_STATUS_CONTROLLER;

/* Controller OBJ */
typedef struct {
  bool                        bInUse;
  char                        Name[MAX_NAME_LENGTH];  // Name of the Controller
  CONTROLLER_TYPE             Type;                   // Type of Controller
  uint16_t                    PinsUsed;               // Init: Total Number of GPIO pins used, set to -1 for no sensor
  OBJ_STATUS_CONTROLLER       StatusCTL;
  OBJ_SETTING_CONTROLLER      SettingCTL;
  OBJ_DEVICEIO                DeviceIO[DEVICE_MAX_ASIZE - 1];
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