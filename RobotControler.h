/**
 * @file RobotControler.h
 * @brief Header file for the RobotControler class, providing an interface for controlling the robot and managing its connection status.
 * @author Elif Fatma Cebeci
 * @date December 2024
 */

#ifndef ROBOTCONTROLER_H
#define ROBOTCONTROLER_H

#include "Pose.h"
#include "FestoRobotAPI.h"

 /**
  * @class RobotControler
  * @brief Manages the control and movement of the robot, as well as its connection to the FestoRobotAPI.
  */
class RobotControler {
private:
    Pose* position;           /**< Pointer to the Pose object representing the robot's position. */
    FestoRobotAPI* robotAPI;  /**< Pointer to the FestoRobotAPI object for robot control. */
    bool connectionStatus;    /**< Status of the connection to the robot. */

public:
    /**
     * @brief Constructor for the RobotControler class.
     * @param position Pointer to the Pose object representing the robot's position.
     * @param robotAPI Pointer to the FestoRobotAPI object for robot control.
     */
    RobotControler(Pose* position, FestoRobotAPI* robotAPI);

    /**
     * @brief Destructor for the RobotControler class.
     * Cleans up dynamically allocated resources.
     */
    ~RobotControler();

    /**
     * @brief Returns the connection status of the robot.
     * @return True if the robot is connected, false otherwise.
     */
    bool Status();

    /**
     * @brief Turns the robot to the left.
     */
    void turnLeft();

    /**
     * @brief Turns the robot to the right.
     */
    void turnRight();

    /**
     * @brief Moves the robot forward.
     */
    void moveForward();

    /**
     * @brief Moves the robot backward.
     */
    void moveBackward();

    /**
     * @brief Moves the robot to the left.
     */
    void moveLeft();

    /**
     * @brief Moves the robot to the right.
     */
    void moveRight();

    /**
     * @brief Stops the robot's movement.
     */
    void stop();

    /**
     * @brief Retrieves the current position of the robot.
     * @return The current position of the robot as a Pose object.
     */
    Pose getPose();

    /**
     * @brief Prints the status and position of the robot to the console.
     */
    void print();

    /**
     * @brief Connects the robot to the FestoRobotAPI.
     * @return True if the connection is successful, false otherwise.
     */
    bool connectRobot();

    /**
     * @brief Disconnects the robot from the FestoRobotAPI.
     * Frees the associated resources and resets the connection status.
     * @return False to indicate the robot is disconnected.
     */
    bool disconnectRobot();
};

#endif // ROBOTCONTROLER_H
