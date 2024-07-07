#pragma once
#include "Sensor.h"
#include <iostream>
#include <map>
#include <string>
#include "SensorTypes.h"

class SensorPool
{
private:
    std::map<int, Sensor*> sensors;
public:
    /**
     * @brief Adds a sensor of the specified type to the sensor pool.
     *
     * @param sensorType The type of the sensor to add.
     */
    void addSensor(const std::string& sensorType);

    /**
     * @brief Lists all the sensors in the sensor pool.
     */
    void listSensors() const;

    /**
     * @brief Removes the sensor with the specified ID from the sensor pool.
     *
     * @param sensorId The ID of the sensor to remove.
     */
    void removeSensor(int sensorId);

    /**
     * @brief Gets the sensor with the specified ID from the sensor pool.
     *
     * @param sensorId The ID of the sensor to get.
     * @return The sensor with the specified ID, or nullptr if not found.
     */
    Sensor* getSensor(int sensorId);
};
