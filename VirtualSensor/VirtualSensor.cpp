// VirtualSensor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <thread>
#include <chrono>
#include "SensorTypes.h"
#include "SensorPool.h"

using namespace std;

int Sensor::nextId = 1;     // Initialize the static member variable
SensorPool sensorPool;

bool waitForCommand = false;

// Command Processor Class
class CommandProcessor {
private:
    
public:
    void processCommand() 
    {
        string command;
        cout << "Enter command (add <sensortype>, list, remove <sensorid>): ";
        waitForCommand = true;
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
            int sensorId = stoi(arg);
            sensorPool.removeSensor(sensorId);
        }
        else
        {
            cout << "Error: Unknown command. Supported commands: add, list, remove." << endl;
        }
        waitForCommand = false;
    }
};

void sensorStream() 
{
    while (true)
    {
        if (waitForCommand)
		{
			continue;
		}
        int n = Sensor::getNextId() - 1;
        if ( n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                Sensor* sensor = sensorPool.getSensor(i + 1);
                sensor->streamData();
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void acceptCommands()
{
    CommandProcessor processor;
    while (true)
    {
        char input;
        cin >> input;
        cin.ignore();
        if (input == 'c')
        {
            processor.processCommand();
        }
    }
}


// Main function
int main() 
{
    std::thread streamThread(sensorStream);
    std::thread commandThread(acceptCommands);
    
    streamThread.join();
    commandThread.join();
    
    return 0;
}