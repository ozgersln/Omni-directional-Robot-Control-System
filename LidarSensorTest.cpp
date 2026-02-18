/**
 * @file LidarSensorTest.cpp
 * @brief Application for testing the operation of the Lidar sensor.
 * @details This application communicates with the robot, collects data from the Lidar sensor,
 * and prints sensor data while the robot moves in various directions.
 * @author Elif Fatma Cebeci
 * @date December, 2024
 */

#include "FestoRobotAPI.h"
#include "LidarSensor.h"
#include <iostream>
using namespace std;

FestoRobotAPI* robotino;

/**
 * @brief Prints Lidar sensor data.
 * @details Collects the smallest and largest values, their indices, and the corresponding
 * angles and distances from the Lidar sensor, and prints them to the console.
 */
void print() {
    // Get pose information
    double x, y, th;
    robotino->getXYTh(x, y, th);

    // Create LidarSensor object
    LidarSensor lidar(robotino);

    // Update Lidar sensor
    lidar.update();

    // Print minimum and maximum Lidar values
    int min, max;
    double minValue = lidar.getMin(min);
    double maxValue = lidar.getMax(max);
    cout << "Min Value: " << minValue << " (Index: " << min << ")" << endl;
    cout << "Max Value: " << maxValue << " (Index: " << max << ")" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // Print Lidar sensor angles and distances
    for (int i = 0; i < robotino->getLidarRangeNumber(); i++) {
        cout << i << ". ";
        cout << "Angle: " << lidar.getAngle(i) << " Distance: " << lidar[i] << " m" << endl;
        cout << "getRange= " << lidar.getRange(i) << endl;
    }
    cout << "----------------------------------------------------------------------" << endl;
}

/**
 * @brief Main function. Moves the robot and retrieves Lidar sensor data.
 * @return Returns 0 to indicate successful program execution.
 */
int main() {
    // Create Robot API object
    robotino = new FestoRobotAPI();

    // Connect to the robot
    robotino->connect();
    Sleep(2000);
    print();

    // Move forward and print sensor data
    robotino->move(FORWARD);
    Sleep(2000);
    robotino->stop();
    print();

    // Move backward and print sensor data
    robotino->move(BACKWARD);
    Sleep(2000);
    robotino->stop();
    print();

    // Move left and print sensor data
    robotino->move(LEFT);
    Sleep(2000);
    robotino->stop();
    print();

    // Move right and print sensor data
    robotino->move(RIGHT);
    Sleep(2000);
    robotino->stop();
    print();

    // Rotate left and print sensor data
    robotino->rotate(LEFT);
    Sleep(2000);
    robotino->stop();
    print();

    // Rotate right and print sensor data
    robotino->rotate(RIGHT);
    Sleep(2000);
    robotino->stop();
    print();

    // Disconnect from the robot
    robotino->disconnect();

    // Delete Robot API object
    delete robotino;

    return 0;
}
