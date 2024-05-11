#ifndef TimerLib_h
#define TimerLib_h

#include "Arduino.h"

typedef void (*CallbackFunction)();  // Definición de tipo para puntero a función

class TimerLib {
public:
    enum TimeType { MILLIS, MICROS };

    TimerLib(unsigned long interval, int maxCallbacks, TimeType type = MILLIS);
    ~TimerLib();
    bool addCallback(CallbackFunction callback);
    void update();

private:
    unsigned long _interval;
    unsigned long _lastTime;  // Último tiempo registrado, ya sea millis o micros
    CallbackFunction* _callbacks;
    int _maxCallbacks;
    int _numCallbacks;
    TimeType _timeType;  // Guarda el tipo de tiempo a utilizar
};

#endif
