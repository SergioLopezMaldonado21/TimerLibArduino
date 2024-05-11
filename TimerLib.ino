#include "TimerLib.h"

TimerLib timer1(10000000, 5, TimerLib::MICROS);  // Crea un timer que dispara cada 10 segundos, usando microsegundos

void setup() {
    Serial.begin(115200);

    // Añade funciones callback al timer
    timer1.addCallback(funcion1);
    timer1.addCallback(funcion2);
}

void loop() {
    timer1.update();  // Actualiza el timer para revisar si es momento de ejecutar los callbacks
}

void funcion1() {
    Serial.println("Función 1 ejecutada con micros");
}

void funcion2() {
    Serial.println("Función 2 ejecutada con micros");
}
