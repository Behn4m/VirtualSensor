#include "SensorTypes.h"
#include <iostream>

// Derived PressureSensor Class
PressureSensor::PressureSensor(int sensorId)
    : Sensor("Pressure", sensorId, 1000U) {}

void PressureSensor::displaySensorInfo() const {
    std::cout << "Pressure Sensor - ID: " << getId() << ", Sampling Rate: " << getSamplingInterval() << " ms" << std::endl;
}

// Derived TemperatureSensor Class
TemperatureSensor::TemperatureSensor(int sensorId)
    : Sensor("Temperature", sensorId, 8000U) {}

void TemperatureSensor::displaySensorInfo() const {
    std::cout << "Temperature Sensor - ID: " << getId() << ", Sampling Rate: " << getSamplingInterval() << " ms" << std::endl;
}

// Derived ConductivitySensor Class
ConductivitySensor::ConductivitySensor(int sensorId)
    : Sensor("Conductivity", sensorId, 16000U) {}

void ConductivitySensor::displaySensorInfo() const {
    std::cout << "Conductivity Sensor - ID: " << getId() << ", Sampling Rate: " << getSamplingInterval() << " ms" << std::endl;
}