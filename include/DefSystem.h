/********************************************
 * THIS IS WHERE YOU DEFINE YOUR CONTROLLER *
 *      AND OTHER DEVICE RELATED OBJS       *
 ********************************************/

{
    true,                   // bool                        bInUse;
    "CTL00_TEST",           // char                        Name[MAX_NAME_LENGTH];  // Name of the Controller
    CTL_TYPE_DEFAULT,       // CONTROLLER_TYPE             Type;                   // Type of Controller
    0,                      // uint16_t                    PinsUsed;               // Init: Total Number of GPIO pins used, set to -1 for no sensor
    {         // OBJ_CONTROLLER_STATUS       StatusCTL;
        // false,              // bool                 bRegistered;
        // 0,                  // uint16_t             idxIO;
        // 0,                  // byte                 connectedDev;
        // STS_INIT,           // SYS_STATE            statusCTL;
        // NET_STS_DISABLED,   // NET_STATE             netCTL;
    },        
    {        // OBJ_CONTROLLER_SETTING      SettingCTL;
        LOG_NONE,       // LOG_STATE             logging;
        false,          // bool                  bNetwork;    // Network
        false,          // bool                  bComm;       // PubSub comm
        false,          // bool                  bHasHAT;     // Connected HAT
        false,          // bool                  bHasIPower;  // Intelligent power supply with feedback
    },        
    {}                     // OBJ_DEVICEIO                DeviceIO[DEVICE_MAX_ASIZE - 1];
}           // OBJ_CONTROLLER

