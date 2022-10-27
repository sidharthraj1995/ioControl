/***************************************************************************
 * PROJECT TO LEARN ABOUT ARDUINO LIBRARIES AND IMPROVE PROGRAMMING SKILLS *
 ***************************************************************************/
#include <Arduino.h>

uint32 count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("<Poop #%d>\n",count++);
  delay(250);
}