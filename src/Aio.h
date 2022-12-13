#ifndef __AIO_H__
#define __AIO_H__


#include "rtc.h"




class StartStop
{
private:
    
public:
    StartStop();
    ~StartStop();

    void Init();
    void Start();       // Start the system; run in Setup; checks and validates all the systems
    void Run();         // Run in Loop ?
    void Update();      // Update status; run in loop?
};



#endif // __AIO_H__