/**********************************************
 * * PROJECT TO LEARN ABOUT ARDUINO LIBRARIES *
 *      * AND IMPROVE PROGRAMMING SKILLS      *
 **********************************************/
// #include <Arduino.h>
#include "rtc.h"


CSystem ProjSys;

OBJ_SYSTEM Obj_sys = {
    "Arkham Labs",  // char                Name[MAX_NAME_LENGTH];
    "2022-11-28",   // char                InitDay0[MAX_DATE_LENGTH];
    {
        "aioControl",           // char        ProjectName[MAX_NAME_LENGTH];
        "Arkham",               // char        Author[MAX_NAME_LENGTH];
        "aioControl v0.6",      // char        Framework[MAX_NAME_LENGTH];
    },              // OBJ_PROJECT_INFO
    #include "DefSystem.h"  // OBJ_CONTROLLER      Controller[CTL_MAX_ASIZE - 1];
};                      // OBJ_SYSTEM





void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // Serial.flush();
  ProjSys.Init(Obj_sys);
  delay(500);
  
  // ProjSys.Register();
  if (ProjSys.Register())
    Serial.println("Register\n");
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(".....");  
  // delay(500);
}
