
/**
 * @file SafeNavigation.cpp
 * @brief Implementation of the SafeNavigation class, providing obstacle-aware navigation for a robot.
 * @author Pariya Jahanbakhsh  (152120231154@ogrenci.ogu.edu.tr)
 * @date December 2024
 */

#include "SafeNavigation.h"
#include <iostream>

using namespace std;

/**
 * @brief Constructor for SafeNavigation class.
 * @param rc Pointer to a RobotControler object for controlling the robot's movement.
 * @param ir Pointer to an IRSensor object for detecting obstacles.
 */
SafeNavigation::SafeNavigation(RobotControler* rc, IRSensor* ir)
    : controller(rc), irSensor(ir), state(STOP) {}

/**
 * @brief Checks if an obstacle is detected by the IR sensor.
 * @return True if an obstacle is detected within a threshold distance, otherwise false.
 */
bool SafeNavigation::isObstacleDetected() {
    irSensor->update(); // Update IR sensor readings
    for (int i = 0; i < 9; ++i) {
        if (irSensor->getRange(i) < 0.5) { // Assuming 0.5 is the threshold for detecting an obstacle
            cout << "Obstacle detected at sensor " << i << " with distance " << irSensor->getRange(i) << endl;
            return true;
        }
    }
    return false;
}

/**
 * @brief Moves the robot forward safely, checking for obstacles.
 */
void SafeNavigation::moveForwardSafe() {
    if (!isObstacleDetected()) {
        controller->moveForward(); // Start moving forward
        state = MOVING;
    }
    else {
        state = STOP;
    }
}

/**
 * @brief Moves the robot backward safely, checking for obstacles.
 */
void SafeNavigation::moveBackwardSafe() {
    if (!isObstacleDetected()) {
        controller->moveBackward(); // Start moving backward
        state = MOVING;
    }
    else {
        state = STOP;
    }
}

/**
 * @brief Retrieves the current state of the robot.
 * @return The current state of the robot (STOP or MOVING).
 */
SafeNavigation::State SafeNavigation::getState() const {
    return state;
}

