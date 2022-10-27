/**********************************************
 * * PROJECT TO LEARN ABOUT ARDUINO LIBRARIES *
 *      * AND IMPROVE PROGRAMMING SKILLS      *
 **********************************************/
#include <Arduino.h>

#define ONBOARD_LED 2


void toggleIO(uint8_t pin);


uint32_t count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ONBOARD_LED, OUTPUT);
  digitalWrite(ONBOARD_LED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("<Poop #%d>\n",count++);
  Serial.println(".");
  toggleIO(ONBOARD_LED);
  delay(250);
}

void toggleIO(uint8_t pin) {
  digitalWrite(pin, !digitalRead(pin));
}