#ifndef SENSORS_TYPES_H
#define SENSORS_TYPES_H

#include "Sensor.h"

// Derived PressureSensor Class
class PressureSensor : public Sensor {
public:
    PressureSensor();

    void displaySensorInfo() const override;
};

// Derived TemperatureSensor Class
class TemperatureSensor : public Sensor {
public:
    TemperatureSensor();

    void displaySensorInfo() const override;
};

// Derived ConductivitySensor Class
class ConductivitySensor : public Sensor {
public:
    ConductivitySensor();

    void displaySensorInfo() const override;
};

#endif // SENSORS_TYPES_H
