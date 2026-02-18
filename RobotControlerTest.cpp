/**
 * @file RobotControlTest.cpp
 * @brief Test application for the RobotControler class and its motion capabilities.
 * @details This application initializes a robot's pose and API, connects to the robot,
 * performs various motion tests, and verifies its position using the RobotControler class.
 * @author Elif Fatma Cebeci
 * @date December, 2024
 */

#include "RobotControler.h"
#include "Pose.h"
#include "FestoRobotAPI.h"
#include <iostream>
using namespace std;

/**
 * @brief Main function for testing the RobotControler class.
 * @details This function creates and initializes the robot's components,
 * performs motion commands, retrieves the current pose, and disconnects the robot.
 *
 * @return Returns 0 upon successful execution.
 */
int main() {
    // Initialize the robot's position and API objects
    Pose* position = new Pose(0.0, 0.0, 0.0);      // Initial position (x, y, theta)
    FestoRobotAPI* robotino = new FestoRobotAPI(); // Simulated robot API object
    RobotControler control(position, robotino);   // Robot controller object

    // Connect the robot
    control.connectRobot();
    cout << "----------------------------------------------------------------------" << endl;

    // Perform motion tests
    control.moveForward();
    Sleep(2000);
    control.stop();
    control.moveBackward();
    Sleep(2000);
    control.stop();
    control.turnLeft();
    Sleep(2000);
    control.stop();
    control.turnRight();
    Sleep(2000);
    control.stop();
    control.moveLeft();
    Sleep(2000);
    control.stop();
    control.moveRight();
    Sleep(2000);
    control.stop();

    cout << "----------------------------------------------------------------------" << endl;

    // Test the getPose() method
    cout << "Testing getPose()..." << endl;
    Pose currentPose = control.getPose();
    cout << "Current Position: x=" << currentPose.getX()
        << ", y=" << currentPose.getY()
        << ", th=" << currentPose.getTh() << endl;

    cout << "----------------------------------------------------------------------" << endl;

    // Print the status of the robot
    control.print();

    // Disconnect the robot
    control.disconnectRobot();

    return 0; // Program executed successfully
}
