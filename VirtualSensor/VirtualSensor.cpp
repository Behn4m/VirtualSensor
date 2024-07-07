// VirtualSensor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SensorTypes.h"


    int main()
    {
        std::cout << "Hi there!" << std::endl;
        int i = 0;

        Sensor* sensor_array[16];

        for (i = 0; i < 16; i ++)
        {
            sensor_array[i] = new PressureSensor(i);
            sensor_array[i]->displaySensorInfo();
        }

        std::cout << "Bye!" << std::endl;
        return 0;
    }