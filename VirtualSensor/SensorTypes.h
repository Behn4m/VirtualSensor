#ifndef SENSORS_TYPES_H
#define SENSORS_TYPES_H

#include "Sensor.h"

// Derived PressureSensor Class
class PressureSensor : public Sensor {
public:
    PressureSensor(int sensorId);

    void displaySensorInfo() const override;
};

// Derived TemperatureSensor Class
class TemperatureSensor : public Sensor {
public:
    TemperatureSensor(int sensorId);

    void displaySensorInfo() const override;
};

// Derived ConductivitySensor Class
class ConductivitySensor : public Sensor {
public:
    ConductivitySensor(int sensorId);

    void displaySensorInfo() const override;
};

#endif // SENSORS_TYPES_H
