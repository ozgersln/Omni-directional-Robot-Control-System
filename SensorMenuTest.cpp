#include <iostream>
#include <iomanip>
#include "SensorMenu.h"
#include "RobotControler.h"
#include "FestoRobotAPI.h"

/**
 * @file SensorMenuTest.cpp
 * @author Mervenur �akmako�lu (152120221128@ogrenci.ogu.edu.tr)
 * @date December 2024
 * @brief Main entry point for testing the SensorMenu class.
 *
 * This program initializes the robot control system, connects to the robot,
 * and displays a sensor menu for interaction. It tests various components
 * like FestoRobotAPI, Pose, and SensorMenu.
 *
 * @return int Exit status of the program (0 for successful execution).
 */
int main() {
    /**
     * @brief Create an instance of the robot API to manage robot operations.
     */
    FestoRobotAPI* robotAPI = new FestoRobotAPI();

    /**
     * @brief Create an initial pose for the robot with default coordinates.
     */
    Pose* initialPose = new Pose(0.0, 0.0, 0.0);

    /**
     * @brief Initialize the robot controller with the initial pose and robot API.
     */
    RobotControler* robotController = new RobotControler(initialPose, robotAPI);

    /**
     * @brief Establish a connection to the robot for further operations.
     */
    robotController->connectRobot();

    /**
     * @brief Create a SensorMenu instance for displaying and managing sensor data.
     */
    SensorMenu sensorMenu(robotController, robotAPI);

    /**
     * @brief Display the sensor menu and allow user interaction.
     */
    sensorMenu.showMenu();

    /**
     * @brief Disconnect the robot after testing is complete.
     */
    robotController->disconnectRobot();

    /**
     * @brief Clean up dynamically allocated memory to prevent memory leaks.
     */
    delete robotController; /**< Deletes the robot controller instance. */
    delete initialPose;     /**< Deletes the initial pose instance. */
    delete robotAPI;        /**< Deletes the robot API instance. */

    return 0; /**< Exit the program successfully. */
}

