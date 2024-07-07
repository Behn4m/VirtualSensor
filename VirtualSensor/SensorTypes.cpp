/**
 * @file SensorTypes.cpp
 * @brief Implementation of the SensorTypes.h file.
 */

#include "SensorTypes.h"
#include <iostream>

/**
 * @class PressureSensor
 * @brief A class representing a pressure sensor.
 */
 
/**
 * @brief Constructs a PressureSensor object.
 * @param sensorId The ID of the sensor.
 */
PressureSensor::PressureSensor()
    : Sensor("Pressure", 1U) {}

/**
 * @brief Displays information about the pressure sensor.
 */
void PressureSensor::displaySensorInfo() const {
    std::cout << "Pressure Sensor - ID: " << getId() << ", Sampling Rate: " << getSamplingInterval() << " ms" << std::endl;
}

/**
 * @class TemperatureSensor
 * @brief A class representing a temperature sensor.
 */
 
/**
 * @brief Constructs a TemperatureSensor object.
 * @param sensorId The ID of the sensor.
 */
TemperatureSensor::TemperatureSensor()
    : Sensor("Temperature", 8U) {}

/**
 * @brief Displays information about the temperature sensor.
 */
void TemperatureSensor::displaySensorInfo() const {
    std::cout << "Temperature Sensor - ID: " << getId() << ", Sampling Rate: " << getSamplingInterval() << " ms" << std::endl;
}

/**
 * @class ConductivitySensor
 * @brief A class representing a conductivity sensor.
 */
 
/**
 * @brief Constructs a ConductivitySensor object.
 * @param sensorId The ID of the sensor.
 */
ConductivitySensor::ConductivitySensor()
    : Sensor("Conductivity", 16U) {}

/**
 * @brief Displays information about the conductivity sensor.
 */
void ConductivitySensor::displaySensorInfo() const {
    std::cout << "Conductivity Sensor - ID: " << getId() << ", Sampling Rate: " << getSamplingInterval() << " ms" << std::endl;
}