#ifndef ROBOT_INTERFACE_H
#define ROBOT_INTERFACE_H

#include "Pose.h"

/**
 * @class RobotInterface
 * @brief Abstract interface class for controlling a robot's movement and connection status.
 *
 * This interface defines the basic methods required to interact with a robot.
 * It serves as a base class for specific implementations that interact with different robot APIs.
 */
class RobotInterface {
protected:
    /**
     * @brief Pointer to the robot's position (Pose object).
     */
    Pose* position;

    /**
     * @brief Status of the robot's connection.
     * @details True if the robot is connected, false otherwise.
     */
    bool connectionStatus;

public:
    /**
     * @brief Default constructor.
     * Initializes the position to nullptr and connectionStatus to false.
     */
    RobotInterface() : position(nullptr), connectionStatus(false) {}

    /**
     * @brief Virtual destructor.
     * Ensures proper cleanup of derived classes.
     */
    virtual ~RobotInterface() {}

    /**
     * @brief Turns the robot to the left.
     */
    virtual void turnLeft() = 0;

    /**
     * @brief Turns the robot to the right.
     */
    virtual void turnRight() = 0;

    /**
     * @brief Moves the robot forward.
     */
    virtual void moveForward() = 0;

    /**
     * @brief Moves the robot backward.
     */
    virtual void moveBackward() = 0;

    /**
     * @brief Moves the robot to the left.
     */
    virtual void moveLeft() = 0;

    /**
     * @brief Moves the robot to the right.
     */
    virtual void moveRight() = 0;

    /**
     * @brief Stops the robot's movement.
     */
    virtual void stop() = 0;

    /**
     * @brief Gets the robot's current position.
     * @return A Pose object representing the robot's position.
     */
    virtual Pose getPose() const = 0;

    /**
     * @brief Prints the robot's status or debug information.
     */
    virtual void print() const = 0;

    /**
     * @brief Connects to the robot.
     * @return True if the connection is successful, false otherwise.
     */
    virtual bool connectRobot() = 0;

    /**
     * @brief Disconnects from the robot.
     * @return True if the disconnection is successful, false otherwise.
     */
    virtual bool disconnectRobot() = 0;
};

#endif // ROBOT_INTERFACE_H
