#include "Sensor.h"
#include <iostream>


// Constructor
Sensor::Sensor(const std::string& sensorType, unsigned int sensorSamplingInterval)
    : type(sensorType), samplingInterval(sensorSamplingInterval) 
{
    	id = nextId++;
}

void Sensor::setType(const std::string& sensorType) 
{
    type = sensorType;
}

void Sensor::setId(int sensorId) 
{
    id = sensorId;
}

void Sensor::setSamplingInterval(unsigned int sensorSamplingInterval) 
{
    sensorSamplingInterval = sensorSamplingInterval;
}

// Getters
std::string Sensor::getType() const 
{
    return type;
}

int Sensor::getId() const {
    return id;
}

double Sensor::getSamplingInterval() const 
{
    return samplingInterval;
}

int Sensor::getNextId() 
{
	return nextId;
}

// streamer
void Sensor::streamData() 
{
    if (remainingTime > 0) {
        remainingTime--;
    }
    else 
    {
        remainingTime = samplingInterval;
        std::cout << "Streaming data from sensor " << id << std::endl;
    }
}

// Method to display sensor details
void Sensor::displaySensorInfo() const 
{
    std::cout << "Sensor Type: " << type << std::endl;
    std::cout << "Sensor ID: " << id << std::endl;
    std::cout << "Sampling interval: " << samplingInterval << " ms" << std::endl;
}
