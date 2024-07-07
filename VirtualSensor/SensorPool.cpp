#include "SensorPool.h"
#include "SensorTypes.h"
#include "Sensor.h"
#include <iostream>

using namespace std;
void SensorPool::addSensor(const string& sensorType)
{
    Sensor* newSensor = nullptr;
    if (sensorType == "pressure")
    {
        newSensor = new PressureSensor();
    }
    else if (sensorType == "temperature")
    {
        newSensor = new TemperatureSensor();
    }
    else if (sensorType == "conductivity")
    {
        newSensor = new ConductivitySensor();
    }
    else
    {
        cout << "Error: Unknown sensor type. Supported types: pressure, temperature, conductivity." << endl;
        return;
    }

    sensors[newSensor->getId()] = newSensor;
    cout << "Sensor of type '" << sensorType << "' added with ID: " << newSensor->getId() << endl;
}

void SensorPool::listSensors() const
{
    cout << "Listing all sensors:" << endl;
    for (const auto& kv : sensors)
    {
        kv.second->displaySensorInfo();
    }
    cout << endl;
}

void SensorPool::removeSensor(int sensorId)
{
    auto it = sensors.find(sensorId);
    if (it == sensors.end())
    {
        cout << "Error: Sensor with ID " << sensorId << " not found." << endl;
    }
    else
    {
        delete it->second;
        sensors.erase(it);
        cout << "Sensor with ID " << sensorId << " removed successfully." << endl;
    }
}

Sensor* SensorPool::getSensor(int sensorId)
{
    auto it = sensors.find(sensorId);
    if (it == sensors.end())
    {
        return nullptr;
    }
    return it->second;
}
