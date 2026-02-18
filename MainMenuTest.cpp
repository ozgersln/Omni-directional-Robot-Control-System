/**
 * @file MainMenuTest.cpp
 * @brief Test the functionality of the MainMenu in a robot system.
 *
 * This file includes the test code for the MainMenu class. It initializes the robot system
 * with appropriate robot and sensor objects, sets up the main menu, and runs the menu to
 * simulate user interactions.
 *
 * @author Elif Fatma Cebeci (152120221123@ogrenci.ogu.edu.tr)
 * @date December, 2024
 */

#include "MainMenu.h"
#include "MotionMenu.h"
#include "SensorMenu.h"
#include "ConnectionMenu.h"
#include "FestoRobotAPI.h"
#include "RobotControler.h"
#include "SafeNavigation.h"
#include "Pose.h"
#include "IRSensor.h"
#include <iostream>

using namespace std;

int main() {
    // Create robot and sensor objects
    /**
     * Initialize the robot's initial pose.
     */
    Pose* initialPose = new Pose(0.0, 0.0, 0.0);          ///< Robot's initial position

    /**
     * Initialize the robot API for controlling the robot.
     */
    FestoRobotAPI* robotAPI = new FestoRobotAPI();          ///< Simulated robot API

    /**
     * Initialize the IR sensor for obstacle detection.
     */
    IRSensor* irSensor = new IRSensor(robotAPI);            ///< Simulated IR sensor

    /**
     * Create the RobotController to manage the robot's motion.
     */
    RobotControler* robotController = new RobotControler(initialPose, robotAPI); ///< Robot controller

    /**
     * Initialize SafeNavigation with robot controller and IR sensor for safe navigation.
     */
    SafeNavigation* safeNav = new SafeNavigation(robotController, irSensor); ///< Safe navigation

    // Create menu objects
    /**
     * Initialize MotionMenu for motion control.
     */
    MotionMenu* motionMenu = new MotionMenu(robotController, safeNav, 0);

    /**
     * Initialize SensorMenu for sensor-related functionality.
     */
    SensorMenu* sensorMenu = new SensorMenu(robotController, robotAPI);

    /**
     * Initialize ConnectionMenu for managing robot connections.
     */
    ConnectionMenu* connectionMenu = new ConnectionMenu(robotController);

    // Create and start the main menu object
    /**
     * Create the MainMenu object and display the menu to the user.
     */
    MainMenu mainMenu(motionMenu, sensorMenu, connectionMenu);
    mainMenu.showMenu();

    // Clean up memory
    /**
     * Clean up allocated memory for the objects.
     */
    delete motionMenu;
    delete sensorMenu;
    delete connectionMenu;
    delete safeNav;
    delete robotController;
    delete irSensor;
    delete robotAPI;
    delete initialPose;

    return 0;
}

