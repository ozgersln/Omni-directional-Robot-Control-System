/**
 * @file RobotMenuTest.cpp
 * @brief Main test file for the RobotMenu system.
 *
 * This file initializes all necessary components for the robot system and runs the RobotMenu.
 * It ensures the proper functioning of motion, sensor, and connection menus along with the main menu.
 *
 * @author Elif Fatma Cebeci (152120221123@ogrenci.ogu.edu.tr)
 * @date December, 2024
 */

#include "RobotMenu.h"
#include "OperatorLoginMenu.h"
#include "MainMenu.h"
#include "MotionMenu.h"
#include "SensorMenu.h"
#include "ConnectionMenu.h"
#include "RobotOperator.h"
#include "FestoRobotAPI.h"
#include "RobotControler.h"
#include "SafeNavigation.h"
#include "Pose.h"
#include "IRSensor.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief Main function to initialize and test the RobotMenu system.
 *
 * This function creates and initializes the necessary robot components such as
 * sensors, controllers, and menus. It then runs the RobotMenu to demonstrate the
 * overall functionality of the system.
 *
 * @return int Returns 0 upon successful execution.
 */
int main() {
    // Initialize robot and sensor objects
    Pose* initialPose = new Pose(0.0, 0.0, 0.0);          ///< Robot's initial position
    FestoRobotAPI* robotAPI = new FestoRobotAPI();        ///< Simulated robot API
    IRSensor* irSensor = new IRSensor(robotAPI);          ///< Simulated IR sensor
    RobotControler* robotController = new RobotControler(initialPose, robotAPI); ///< Robot controller
    SafeNavigation* safeNav = new SafeNavigation(robotController, irSensor);    ///< Safe navigation system

    // Create menu objects
    MotionMenu* motionMenu = new MotionMenu(robotController, safeNav, 0); ///< Motion control menu
    SensorMenu* sensorMenu = new SensorMenu(robotController, robotAPI);   ///< Sensor data menu
    ConnectionMenu* connectionMenu = new ConnectionMenu(robotController); ///< Connection management menu

    // Create MainMenu object
    MainMenu mainMenu(motionMenu, sensorMenu, connectionMenu); ///< Main menu combining all submenus

    // Create and run RobotMenu
    RobotMenu robotMenu(&mainMenu);
    robotMenu.run(); ///< Run the RobotMenu to interact with the robot system

    // Clean up memory
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
