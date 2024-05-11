#include "TimerLib.h"

TimerLib::TimerLib(unsigned long interval, int maxCallbacks, TimeType type)
: _interval(interval), _maxCallbacks(maxCallbacks), _numCallbacks(0), _lastTime(0), _timeType(type) {
    _callbacks = new CallbackFunction[maxCallbacks];
}

TimerLib::~TimerLib() {
    delete[] _callbacks;
}

bool TimerLib::addCallback(CallbackFunction callback) {
    if (_numCallbacks < _maxCallbacks) {
        _callbacks[_numCallbacks++] = callback;
        return true;
    }
    return false;
}

void TimerLib::update() {
    unsigned long currentTime;
    if (_timeType == MICROS) {
        currentTime = micros();
    } else {
        currentTime = millis();
    }

    if (currentTime - _lastTime >= _interval) {
        _lastTime = currentTime;
        for (int i = 0; i < _numCallbacks; i++) {
            _callbacks[i]();  // Ejecuta cada callback registrado
        }
    }
}
