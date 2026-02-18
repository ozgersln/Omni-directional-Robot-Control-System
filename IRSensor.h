#ifndef IRSENSOR_H
#define IRSENSOR_H

#include "FestoRobotAPI.h"

class IRSensor {
protected:
    FestoRobotAPI* robotAPI;
    double ranges[9]; // Array to hold sensor ranges

public:
    // Constructor
    explicit IRSensor(FestoRobotAPI* api);

    // Virtual destructor to ensure proper cleanup
    virtual ~IRSensor() = default;

    // Virtual method to update sensor values
    virtual void update();

    // Virtual method to get a specific range value
    virtual double getRange(int index);

    // Virtual operator[] for accessing ranges
    virtual double operator[](int index);
};

#endif // IRSENSOR_H


