// VirtualSensor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "SensorTypes.h"

using namespace std;

// Command Processor Class
class CommandProcessor {
private:

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

        }
        else if (action == "list") 
        {

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