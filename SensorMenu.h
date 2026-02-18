#ifndef SENSORMENU_H
#define SENSORMENU_H

#include "FestoRobotAPI.h"
#include "IRSensor.h"
#include "LidarSensor.h"
#include "Pose.h"
#include "RobotControler.h"

/**
 * @class SensorMenu
 * @brief Sensor data interaction menu for a robot.
 *
 * This class provides functionality to interact with various sensors
 * such as IR and Lidar sensors, display the robot's position, and
 * manage user interactions through a menu system.
 *
 * @author Mervenur �akmako�lu (152120221128@ogrenci.ogu.edu.tr)
 * @date December 2024
 */
class SensorMenu {
private:
    FestoRobotAPI* robotAPI;        /**< Pointer to the robot's API for managing operations. */
    IRSensor* irSensor;             /**< Pointer to the IR sensor object for retrieving IR sensor data. */
    LidarSensor* lidarSensor;       /**< Pointer to the Lidar sensor object for retrieving Lidar sensor data. */
    Pose robotPose;                 /**< Object representing the robot's current position (x, y, theta). */
    int sensorChoice;               /**< Variable to store the user's menu selection. */
    RobotControler* Control;        /**< Pointer to the robot controller for managing robot states. */

    /**
     * @brief Displays the robot's current position.
     *
     * This function retrieves and prints the robot's position (x, y, and theta).
     */
    void displayPose();

    /**
     * @brief Displays the IR sensor data.
     *
     * This function retrieves and prints the IR sensor readings.
     */
    void displayIRSensorData();

    /**
     * @brief Displays the Lidar sensor data.
     *
     * This function retrieves and prints the Lidar sensor readings,
     * including the minimum and maximum ranges.
     */
    void displayLidarSensorData();

    /**
     * @brief Handles the user's menu selection.
     *
     * Processes the user's input to execute the corresponding functionality.
     */
    void handleChoice();

public:
    /**
     * @brief Constructor for the SensorMenu class.
     * @param control Pointer to the RobotControler object.
     * @param api Pointer to the FestoRobotAPI object.
     *
     * Initializes the SensorMenu with the given robot controller and API pointers.
     */
    SensorMenu(RobotControler* control, FestoRobotAPI* api);

    /**
     * @brief Destructor for the SensorMenu class.
     *
     * Frees the dynamically allocated resources, such as IR and Lidar sensors.
     */
    ~SensorMenu();

    /**
     * @brief Displays the sensor menu.
     *
     * This function shows the sensor menu and allows the user to interact
     * with various functionalities such as viewing the robot's position and sensor data.
     */
    void showMenu();
};

#endif // SENSORMENU_H