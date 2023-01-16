#include "Aio.h"

CController *cctl;
CSystem     *csys;
CDeviceIO   *cdev;


// Constructor - calls rtc constructors and passes required args 
StartStop::StartStop() {
}

StartStop::~StartStop() {
    // delete *cctl;
    // delete *csys;
    // delete *cdev;
}

void StartStop::Init(OBJ_SYSTEM Sys) {
    csys->Init(Sys);
    // cctl->Init()
    
}

void StartStop::Start() {

}

void StartStop::Run() {
    
}

void StartStop::Update() {

}