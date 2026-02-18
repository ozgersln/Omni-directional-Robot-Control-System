/*
* SafeNavigation.h
* author Pariya Jahanbakhsh (152120231154@ogrenci.ogu.edu.tr)
* date: december, 2024
*/


#ifndef SAFENAVIGATION_H
#define SAFENAVIGATION_H

#include "RobotControler.h"
#include "IRSensor.h"
#include <iostream>

class SafeNavigation {
public:
    // Enum to track the state of the robot
    enum State {
        STOP,
        MOVING
    };

    // Constructor
    SafeNavigation(RobotControler* rc, IRSensor* ir);

    // Function to check if an obstacle is detected
    bool isObstacleDetected();

    // Function to move the robot forward safely
    void moveForwardSafe();

    // Function to move the robot backward safely
    void moveBackwardSafe();

    // Getter for the current state of the robot
    State getState() const;

private:
    RobotControler* controller;
    IRSensor* irSensor;
    State state; // The state of the robot (STOP or MOVING)
};

#endif // SAFENAVIGATION_H
