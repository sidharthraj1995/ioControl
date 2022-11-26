/**********************************************
 * * PROJECT TO LEARN ABOUT ARDUINO LIBRARIES *
 *      * AND IMPROVE PROGRAMMING SKILLS      *
 **********************************************/
// #include <Arduino.h>
#include "rtc.h"


CSystem ProjSys;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  ProjSys.Init();

  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(".....");  
  delay(500);
}
