/**************************************
 * THIS LIBRARY HANDLES EVENT LOGGING *
 **************************************/
#ifndef A_EVENTLOG_h
#define A_EVENTLOG_h

#include "enum.h"


enum LOG_LEVEL {
    LOG_SYSTEM = 0,
    LOG_CONTROLLER,
    LOG_DEVICE
};




class EventLog
{
private:
    /* data */
public:
    EventLog();
    ~EventLog();
    bool Init();

    void WriteLog(LOG_LEVEL, char* Text);
    void WriteLog(LOG_LEVEL, char* Text, ...);  // Figure it out
};

EventLog::EventLog()
{
}

EventLog::~EventLog()
{
}






#endif