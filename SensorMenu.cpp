#include <iostream>
#include <iomanip>
#include "SensorMenu.h"
using namespace std;

/**
 * @file SensorMenu.cpp
 * @brief Implementation of the SensorMenu class.
 *
 * This file contains the implementation of the SensorMenu class,
 * providing functionality for interacting with robot sensors through a menu system.
 *
 * @author Mervenur �akmako�lu (152120221128@ogrenci.ogu.edu.tr)
 * @date December 2024
 */

 // Constructor
 /**
  * @brief Constructs a SensorMenu object.
  * @param control Pointer to the RobotControler object.
  * @param api Pointer to the FestoRobotAPI object.
  *
  * Initializes the SensorMenu with the provided RobotControler and FestoRobotAPI objects.
  * Dynamically creates instances of IRSensor and LidarSensor.
  */
SensorMenu::SensorMenu(RobotControler* control, FestoRobotAPI* api) : Control(control), robotAPI(api) {
    irSensor = new IRSensor(robotAPI);     // Create IR sensor
    lidarSensor = new LidarSensor(robotAPI); // Create Lidar sensor
}

// Destructor
/**
 * @brief Destroys the SensorMenu object.
 *
 * Releases dynamically allocated memory for IRSensor and LidarSensor objects.
 */
SensorMenu::~SensorMenu() {
    delete irSensor;      // Free memory
    delete lidarSensor;   // Free memory
}

// Show the sensor menu
/**
 * @brief Displays the sensor menu.
 *
 * Shows the menu options to the user and handles the menu interactions
 * in a loop until the user chooses to exit.
 */
void SensorMenu::showMenu() {
    do {
        cout << "\n=== Sensor Menu ===\n";
        cout << "1. Display Pose\n";
        cout << "2. Display IR Sensor Data\n";
        cout << "3. Display Lidar Sensor Data\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> sensorChoice;

        handleChoice(); // Handle user choice
    } while (sensorChoice != 4);
}

// Handle user choice
/**
 * @brief Handles the user's menu selection.
 *
 * Processes the user's input and executes the corresponding functionality
 * based on the selected menu option.
 */
void SensorMenu::handleChoice() {
    if (!Control->Status()) {
        cout << "The robot is off." << endl;
        return;
    }
    switch (sensorChoice) {
    case 1:
        displayPose();
        break;
    case 2:
        displayIRSensorData();
        break;
    case 3:
        displayLidarSensorData();
        break;
    case 4:
        cout << "Returning to main menu...\n";
        break;
    default:
        cout << "Invalid choice. Please try again.\n";
        break;
    }
}

// Display the robot's pose
/**
 * @brief Displays the robot's current pose.
 *
 * Retrieves the robot's position (x, y, theta) using the FestoRobotAPI
 * and prints the data to the console.
 */
void SensorMenu::displayPose() {
    double x, y, th;
    robotAPI->getXYTh(x, y, th); // Get pose data
    robotPose.setPose(x, y, th); // Update pose

    cout << fixed << setprecision(2);
    cout << "\nRobot Pose:\n";
    cout << "X: " << robotPose.getX() << " meters\n";
    cout << "Y: " << robotPose.getY() << " meters\n";
    cout << "Theta: " << robotPose.getTh() << " degrees\n";
}

// Display IR sensor data
/**
 * @brief Displays the IR sensor data.
 *
 * Updates and prints the IR sensor readings for all sensors.
 */
void SensorMenu::displayIRSensorData() {
    irSensor->update(); // Update sensor data
    cout << "\nIR Sensor Ranges:\n";
    for (int i = 0; i < 9; i++) {
        cout << "Sensor " << i << ": " << irSensor->getRange(i) << " meters\n";
    }
}

// Display Lidar sensor data
/**
 * @brief Displays the Lidar sensor data.
 *
 * Updates and prints the Lidar sensor readings, including ranges for all angles,
 * and highlights the minimum and maximum ranges with their respective indices.
 */
void SensorMenu::displayLidarSensorData() {
    lidarSensor->update(); // Update sensor data
    int rangeNum = lidarSensor->getRangeNum();
    if (rangeNum <= 0) {
        cout << "\nNo Lidar data available.\n";
        return;
    }

    cout << "\nLidar Sensor Ranges:\n";
    for (int i = 0; i < rangeNum; i++) {
        cout << "Angle: " << lidarSensor->getAngle(i)
            << " degrees, Range: " << lidarSensor->getRange(i) << " meters\n";
    }

    int maxIndex, minIndex;
    double maxRange = lidarSensor->getMax(maxIndex);
    double minRange = lidarSensor->getMin(minIndex);
    cout << "\nMaximum Range: " << maxRange << " meters at index " << maxIndex << "\n";
    cout << "Minimum Range: " << minRange << " meters at index " << minIndex << "\n";
}