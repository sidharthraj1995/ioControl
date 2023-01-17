#include "Aio.h"

CController *cctl;
CSystem     *csys;
CDeviceIO   *cdev;


// Constructor - calls rtc constructors and passes required args 
Aio::Aio() {
}

Aio::~Aio() {
    // delete *cctl;
    // delete *csys;
    // delete *cdev;
}

void Aio::Init(OBJ_SYSTEM Sys) {
    csys->Init(Sys);
    // cctl->Init()
    
}

void Aio::Start() {

}

void Aio::Run() {
    
}

void Aio::Update() {

}