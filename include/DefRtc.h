#ifndef A_DEF_RTC_h
#define A_DEF_RTC_h

#include "ObjRtc.h"



OBJ_SYSTEM Obj_sys = {
    "Arkham Labs",  // char                Name[MAX_NAME_LENGTH];
    "2022-11-24",   // char                InitDay0[MAX_DATE_LENGTH];
    {
        // OBJ_PROJECT_INFO
        "aioControl",           // char        ProjectName[MAX_NAME_LENGTH];
        "Arkham",               // char        Author[MAX_NAME_LENGTH];
        "aioControl v0.5",      // char        Framework[MAX_NAME_LENGTH];
        // 1                     // uint16_t    FrameworkVersion;
    },
    {0}
    // #include "DefSystem.h"  // OBJ_CONTROLLER      Controller[CTL_MAX_ASIZE - 1];
};                      // OBJ_SYSTEM

#endif