#ifndef __TRACEPRINT_H__
#define __TRACEPRINT_H__

#include <enum.h>

void tracePrint(MESSAGE_TYPE type, MESSAGE_MODULE module, String  String message) {
    String timestamp = String(millis());        // TODO: setup NTP and replace with true current time
    switch(type) {
        case MESSAGE:
            Serial.print("[" + timestamp + "] ");
            Serial.print(" <" + String(module) + "> ");
            Serial.println(message);
        case ERROR:
            Serial.print("[" + timestamp + "] ");
            Serial.print(" <" + String(module) + "> Error:");
            Serial.println(message);
    }
}


#endif // __TRACEPRINT_H__