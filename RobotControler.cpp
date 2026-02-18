/**
 * @file RobotControler.cpp
 * @brief Implementation of the RobotControler class for managing robot movements and connection status.
 * @author Elif Fatma Cebeci
 * @date December 2024
 */

#include "RobotControler.h"
#include <iostream>
using namespace std;

/**
 * @brief Constructor for the RobotControler class.
 * @param position Pointer to the robot's initial position (Pose object).
 * @param robotAPI Pointer to the FestoRobotAPI object for controlling the robot.
 */
RobotControler::RobotControler(Pose* position, FestoRobotAPI* robotAPI)
    : position(position), robotAPI(robotAPI), connectionStatus(false) {}

/**
 * @brief Destructor for the RobotControler class.
 * Deletes the dynamically allocated Pose and FestoRobotAPI objects.
 */
RobotControler::~RobotControler() {
    delete position;
    delete robotAPI;
}

/**
 * @brief Retrieves the current connection status of the robot.
 * @return True if the robot is connected, false otherwise.
 */
bool RobotControler::Status() {
    return connectionStatus;
}

/**
 * @brief Rotates the robot to the left.
 * Executes the operation only if the robot is connected.
 */
void RobotControler::turnLeft() {
    if (robotAPI && connectionStatus) {
        robotAPI->rotate(DIRECTION::LEFT);
    }
}

/**
 * @brief Rotates the robot to the right.
 * Executes the operation only if the robot is connected.
 */
void RobotControler::turnRight() {
    if (robotAPI && connectionStatus) {
        robotAPI->rotate(DIRECTION::RIGHT);
    }
}

/**
 * @brief Moves the robot forward.
 * Executes the operation only if the robot is connected.
 */
void RobotControler::moveForward() {
    if (robotAPI && connectionStatus) {
        robotAPI->move(DIRECTION::FORWARD);
    }
}

/**
 * @brief Moves the robot backward.
 * Executes the operation only if the robot is connected.
 */
void RobotControler::moveBackward() {
    if (robotAPI && connectionStatus) {
        robotAPI->move(DIRECTION::BACKWARD);
    }
}

/**
 * @brief Moves the robot to the left.
 * Executes the operation only if the robot is connected.
 */
void RobotControler::moveLeft() {
    if (robotAPI && connectionStatus) {
        robotAPI->move(DIRECTION::LEFT);
    }
}

/**
 * @brief Moves the robot to the right.
 * Executes the operation only if the robot is connected.
 */
void RobotControler::moveRight() {
    if (robotAPI && connectionStatus) {
        robotAPI->move(DIRECTION::RIGHT);
    }
}

/**
 * @brief Stops the robot's motion.
 * Executes the operation only if the robot is connected.
 */
void RobotControler::stop() {
    if (robotAPI && connectionStatus) {
        robotAPI->stop();
    }
}

/**
 * @brief Retrieves the current pose of the robot (x, y, and theta).
 * @return The current pose of the robot as a Pose object.
 */
Pose RobotControler::getPose() {
    if (robotAPI) {
        double x = position->getX();
        double y = position->getY();
        double th = position->getTh();
        robotAPI->getXYTh(x, y, th);
        position->setPose(x, y, th);
        return *position;
    }
    return Pose();
}

/**
 * @brief Prints the status and position of the robot.
 * Displays whether the robot is connected and its current pose (x, y, theta).
 */
void RobotControler::print() {
    if (robotAPI && connectionStatus) {
        cout << "Robot is open" << endl;
        if (position) {
            double x1 = position->getX();
            double y1 = position->getY();
            double th1 = position->getTh();
            cout << "Position:" << endl;
            cout << "x = " << x1 << endl;
            cout << "y = " << y1 << endl;
            cout << "th = " << th1 << endl;
        }
    }
    else {
        cout << "Robot is not open" << endl;
    }
}

/**
 * @brief Connects the robot to the FestoRobotAPI.
 * @return True if the connection is successful, false otherwise.
 */
bool RobotControler::connectRobot() {
    if (robotAPI) {
        robotAPI->connect();
        connectionStatus = true;
    }
    return connectionStatus;
}

/**
 * @brief Disconnects the robot from the FestoRobotAPI.
 * Frees the memory allocated for the robotAPI object and resets the pointer.
 * @return False to indicate the robot is disconnected.
 */
bool RobotControler::disconnectRobot() {
    if (robotAPI) {
        robotAPI->disconnect();
        connectionStatus = false;
        delete robotAPI; // Free the allocated memory
        robotAPI = nullptr; // Reset the pointer to nullptr
    }
    return connectionStatus;
}
