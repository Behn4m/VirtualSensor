// VirtualSensor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "SensorTypes.h"

using namespace std;

int Sensor::nextId = 1;     // Initialize the static member variable

class SensorPool {
private:
    map<int, Sensor*> sensors;

public:
    void addSensor(const string& sensorType) 
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

    void listSensors() const 
    {
        cout << "Listing all sensors:" << endl;
        for (const auto& kv : sensors) 
        {
            kv.second->displaySensorInfo();
        }
        cout << endl;
    }

    void removeSensor(int sensorId) 
    {

    }
};

// Command Processor Class
class CommandProcessor {
private:
    SensorPool sensorPool;

public:
    void processCommand() 
    {
        string command;
        cout << "Enter command (add <sensortype>, list, remove <sensorid>): ";
        getline(cin, command);

        // Parse command
        string action;
        string arg;
        size_t pos = command.find(' ');
        if (pos != string::npos) 
        {
            action = command.substr(0, pos);
            arg = command.substr(pos + 1);
        }
        else 
        {
            action = command;
        }

        // Process command
        if (action == "add") 
        {
            sensorPool.addSensor(arg);
        }
        else if (action == "list") 
        {
			sensorPool.listSensors();
		}
        else if (action == "remove") 
        {

        }
        else
        {
            cout << "Error: Unknown command. Supported commands: add, list, remove." << endl;
        }
    }
};


// Main function
int main() 
{
    CommandProcessor processor;

    while (1)
    {
        processor.processCommand();
        cout << endl;
    }

    return 0;
}