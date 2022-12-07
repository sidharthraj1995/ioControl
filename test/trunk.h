// Scrap code here


/*

class Event {
  public:
    virtual void handle() = 0;
};

class EventLeft : public Event {
  public:
    virtual void handle() {
      Serial.println("EventLeft");
    }
} leftEvent;

class EventRight : public Event {
  public:
    virtual void handle() {
      Serial.println("EventRight");
    }
} rightEvent;

class PushButton {
  public:
    PushButton(int8_t _pin, Event * _event) : pin(_pin), state(true), event(_event) {
      pinMode(pin, INPUT_PULLUP);
    }

    void check() {
      if (! digitalRead(pin)) { // inverted logic
        if (state) event->handle();
        state = false;
      } else {
        state = true;
      }
    }

  private:
    int8_t    pin;
    bool    state;
    Event * event;
};

PushButton buttons[] = {
  {4, &leftEvent},
  {5, &rightEvent}
};

void setup()   {    
  Serial.begin(115200);
}

void loop() {
  delay(10);

  for (PushButton & button : buttons) button.check();
  //// if the range based for loop above doesn't work, you have to use old school one:
  // for (uint8_t i = 0; i < 2; ++i) buttons[i].check();
}







*/