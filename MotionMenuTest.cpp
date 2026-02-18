/**
 * @file MotionMenuTest.cpp
 * @brief Test application for the MotionMenu class and related functionalities.
 * @details This application simulates the creation of motion control components,
 * tests the MotionMenu interface, and demonstrates robot navigation capabilities.
 * @author Elif Fatma Cebeci
 * @date December, 2024
 */

#include "MotionMenu.h"
#include "RobotControler.h"
#include "SafeNavigation.h"
#include "IRSensor.h"
#include <iostream>
using namespace std;

/**
 * @brief Main function for testing the MotionMenu and navigation system.
 * @details This function initializes the robot's simulation components, displays the motion menu,
 * handles robot connection, and ensures safe navigation using an IR sensor.
 *
 * @return Returns 0 if the program executes successfully; -1 if the robot connection fails.
 */
int main() {
    // Initialize the robot's initial pose
    Pose initialPose(0.0, 0.0, 0.0); // The robot's starting position (x, y, theta)

    // Create simulation components
    FestoRobotAPI robotAPI;                      // Simulated robot API
    IRSensor irSensor(&robotAPI);               // Simulated IR sensor
    RobotControler robotController(&initialPose, &robotAPI); // Robot controller
    SafeNavigation safeNav(&robotController, &irSensor);    // Safe navigation handler

    // Attempt to connect the robot
    if (!robotController.connectRobot()) {
        cerr << "Failed to connect to the robot!" << endl; // Print error message if connection fails
        return -1; // Exit the program with an error code
    }

    // Create and initialize the MotionMenu
    int initialChoice = 0; // Default starting menu choice
    MotionMenu motionMenu(&robotController, &safeNav, initialChoice);

    // Display the MotionMenu and handle user input
    motionMenu.showMenu();

    // Disconnect the robot after testing
    robotController.disconnectRobot();

    return 0; // Program executed successfully
}
