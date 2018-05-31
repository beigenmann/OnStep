// -----------------------------------------------------------------------------------------------------------------------------
// Handle push buttons

#pragma once

class button {
  public:
    void init(int pin, unsigned long debounceMs, boolean pullup) {
      _pin=pin;
      _debounceMs=debounceMs;
      if (pullup) pinMode(pin,INPUT_PULLUP); else pinMode(pin,INPUT);
    }
    // must be repeatedly called to check status of button
    void poll() {
      int lastState=_state;
      _state=digitalRead(_pin);
      if (lastState!=_state) { _avgPulseDuration=((_avgPulseDuration*49.0)+(double)(millis()-_stableStartMs))/50.0; _stableStartMs=millis(); }
      _stableMs=(long)(millis()-_stableStartMs);
      if (_stableMs>3000UL) { _avgPulseDuration=((_avgPulseDuration*4.0)+2000.0)/5.0; }
      if (_stableMs>_debounceMs) { if ((_lastStableState==HIGH) && (_state==LOW)) _wasPressed=true; _lastStableState=_state; }
    }
    // is the button down (LOW)
    bool isDown() { if ((_stableMs>_debounceMs) && (_state==LOW)) return true; else return false; }
    // was the button down (LOW) since last checked
    bool wasPressed() { if (_wasPressed) { _wasPressed=false; return true; } else return false; }
    // is the button up (HIGH)
    bool isUp() { if ((_stableMs>_debounceMs) && (_state==HIGH)) return true; else return false; }
    // number of ms down
    long timeDown() { if ((_stableMs>_debounceMs) && (_state==LOW)) return _stableMs; else return 0; }
    // number of ms up
    long timeUp() { if ((_stableMs>_debounceMs) && (_state==HIGH)) return _stableMs; else return 0; }
    // check to see if this button has the SHC tone
    boolean hasTone() { if (fabs(_avgPulseDuration-40.0)<5.0) return true; else return false; }
    double toneFreq() {return _avgPulseDuration; }
  private:
    int _pin;
    int _state = HIGH;
    int _lastStableState = HIGH;
    unsigned long _debounceMs = 0;
    unsigned long _stableStartMs = 0;
    unsigned long _stableMs = 0;
    boolean _wasPressed = false;
    double _avgPulseDuration = 2000.0;
};
