/**
 * @file LidarSensor.cpp
 * @brief Implementation of the LidarSensor class for processing Lidar sensor data.
 *
 * This file contains the implementation of the LidarSensor class, which provides
 * functionalities for interacting with Lidar sensor data, including retrieving
 * ranges, finding minimum and maximum values, and updating sensor data.
 *
 * @author Elif Fatma Cebeci (152120221123@ogrenci.ogu.edu.tr)
 * @date December, 2024
 */

#include "LidarSensor.h"
#include <iostream>
using namespace std;

/**
 * @brief Constructor for the LidarSensor class.
 *
 * Initializes the FestoRobotAPI pointer and default values.
 *
 * @param robotAPI Pointer to the FestoRobotAPI object.
 */
LidarSensor::LidarSensor(FestoRobotAPI* robotAPI) : robotAPI(robotAPI), ranges(nullptr), rangeNumber(0) {}

/**
 * @brief Destructor for the LidarSensor class.
 *
 * Frees the dynamically allocated memory for ranges.
 */
LidarSensor::~LidarSensor() {
    delete[] ranges;
}

/**
 * @brief Returns the range at the specified index.
 *
 * If the index is invalid, returns -1.
 *
 * @param index Index of the range to retrieve.
 * @return The range value at the specified index, or -1 if the index is invalid.
 */
double LidarSensor::getRange(int index) const {
    if (index >= 0 && index < rangeNumber) {
        return ranges[index];
    }
    return -1;
}

/**
 * @brief Returns the number of ranges available from the Lidar sensor.
 *
 * @return The number of ranges.
 */
int LidarSensor::getRangeNum() const {
    return rangeNumber;
}

/**
 * @brief Finds and returns the maximum range value and its index.
 *
 * If no valid ranges are available, returns -1.
 *
 * @param index Reference to store the index of the maximum range.
 * @return The maximum range value, or -1 if no valid ranges exist.
 */
double LidarSensor::getMax(int& index) const {
    if (rangeNumber == 0) return -1;
    double max1 = ranges[0];
    index = 0;
    for (int i = 0; i < rangeNumber; i++) {
        if (ranges[i] > max1) {
            max1 = ranges[i];
            index = i;
        }
    }
    return max1;
}

/**
 * @brief Finds and returns the minimum range value and its index.
 *
 * If no valid ranges are available, returns -1.
 *
 * @param index Reference to store the index of the minimum range.
 * @return The minimum range value, or -1 if no valid ranges exist.
 */
double LidarSensor::getMin(int& index) const {
    if (rangeNumber == 0) return -1;
    double min1 = ranges[0];
    index = 0;
    for (int i = 0; i < rangeNumber; i++) {
        if (ranges[i] < min1) {
            min1 = ranges[i];
            index = i;
        }
    }
    return min1;
}

/**
 * @brief Updates the range data from the Lidar sensor.
 *
 * Retrieves the latest range data from the robot API and updates the internal state.
 * If the API fails or the pointer is null, displays an error message.
 */
void LidarSensor::update() {
    if (robotAPI) {
        rangeNumber = robotAPI->getLidarRangeNumber();
        if (rangeNumber > 0) {
            delete[] ranges; // Free old range data
            ranges = new float[rangeNumber];
            robotAPI->getLidarRange(ranges);
        }
        else {
            cout << "Failed to retrieve Lidar sensor data!" << endl;
        }
    }
    else {
        cout << "RobotAPI pointer is null!" << endl;
    }
}

/**
 * @brief Overloads the [] operator to access ranges by index.
 *
 * If the index is invalid, returns -1.
 *
 * @param i Index of the range to access.
 * @return The range value at the specified index, or -1 if the index is invalid.
 */
double LidarSensor::operator[](int i) {
    if (i >= 0 && i < rangeNumber) {
        return ranges[i];
    }
    return -1;
}

/**
 * @brief Calculates and returns the angle for a given index.
 *
 * Uses a fixed starting angle and increment per index to calculate the angle.
 *
 * @param i Index for which to calculate the angle.
 * @return The calculated angle.
 */
double LidarSensor::getAngle(int i) const {
    double startAngle = -120.0; // Starting angle
    double angleIncrement = 0.36; // Angle increment per index
    return startAngle + (i * angleIncrement);
}
