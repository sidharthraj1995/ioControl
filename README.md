# 1. Arduino - AIO

+ [1. Arduino - AIO](#1-arduino---aio)
   + [1.1. Introduction](#11-introduction)
   + [1.2. System Layout](#12-system-layout)
   + [1.3. System Components](#13-system-components)

<!-- ## 1.1. File tree 
├─ include
│  ├─ Alert.h
│  ├─ ControlIO.h
│  ├─ Hardware.cpp
│  ├─ Hardware.h
│  ├─ Logging.h
│  ├─ README
│  ├─ enum.h
│  ├─ rtc.cpp
│  └─ rtc_config.h
├─ lib
│  └─ README
├─ platformio.ini
├─ src
│  ├─ aio.drawio
│  ├─ main.cpp
│  └─ scratchPad.md
└─ test
   └─ README -->


## 1.1. Introduction

A new type of Arduino Framework, capable of working with your microController and apt to handle Digital/Analog IOs. The famework is designed to distribute all the roles in modules and seamlessly integrate them.

This is a project to improve my skills and learn something new!

## 1.2. System Layout

```
- System
    - RTC
        > Controller
    - Modules
        > Hardware
            $ ControlIO
            $ Full HAT
            $ Power
            $ Display
        > Software
            $ Network
            $ Comms
            $ Timers
            $ Logs
```

## 1.3. System Components
- ### System: A system is a group of an RTC and multiple modules, aligned together to perform a task.

    - ### RTC: Real-Time Controller is a microController capable of handling Digital/Analog IOs.
        -   ### MicroController: Arduino, ESP8266, ESP32
        -   ### Remote Server: Raspberry, 
    - ### Modules: These are Physical and Virtual modules capable of providing a framework to integrate various IOs together to perform the required task.
        - ### Hardware
            - #### Basic IO Control: Capable of handling basic Input and Output devices, Analog and Digital.
            - #### HAT: A hat is a shield with a bunch of digital and analog IOs.
            - #### Power: It is a ccretical part of the system, system covers basic Power setup and monitoring(future scope)
            - #### Display (Future scope)
        - ### Software
            - #### Network: WiFi/BLE setup, capable of handling network.
            - #### Comms: This is dedicated module to handling communication like PubSub.
            - #### Logs: Modules to handle event logging, local and remote.
            - #### Timers: Non-blocking function to trigger timed based events.

<!-- ## 1.3. How does it work? -->

