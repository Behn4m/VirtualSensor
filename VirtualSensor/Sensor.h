#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>

/**
 * @class Sensor
 * @brief Represents a sensor with its type, ID, and sampling interval.
 */
class Sensor {
private:
    std::string type;
    static int nextId;
    int id = 0;
    unsigned int samplingInterval;

public:
    /**
     * @brief Display the sensor information.
     */
    virtual void displaySensorInfo() const;

    /**
     * @brief Constructor for the Sensor class.
     * 
     * @param sensorType The type of the sensor.
     * @param sensorId The ID of the sensor.
     * @param sensorSamplingInterval The sampling interval of the sensor in milliseconds.
     */
    Sensor(const std::string& sensorType, unsigned int sensorSamplingInterval);

    /**
     * @brief Set the type of the sensor.
     * 
     * @param sensorType The type of the sensor.
     */
    void setType(const std::string& sensorType);

    /**
     * @brief Set the ID of the sensor.
     * 
     * @param sensorId The ID of the sensor.
     */
    void setId(int sensorId);

    /**
     * @brief Set the sampling interval of the sensor in milliseconds.
     * 
     * @param sensorSamplingInterval The sampling interval of the sensor in milliseconds.
     */
    void setSamplingInterval(unsigned int sensorSamplingInterval);

    /**
     * @brief Get the type of the sensor.
     * 
     * @return The type of the sensor.
     */
    std::string getType() const;

    /**
     * @brief Get the ID of the sensor.
     * 
     * @return The ID of the sensor.
     */
    int getId() const;


    /**
     * @brief Get the sampling interval of the sensor in milliseconds.
     * 
     * @return The sampling interval of the sensor in milliseconds.
     */
    double getSamplingInterval() const;
};


#endif // SENSOR_H