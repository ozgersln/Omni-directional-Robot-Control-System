/**
 * @file LidarSensor.h
 * @brief Declaration of the LidarSensor class
 * @details This class interfaces with the FestoRobotAPI to retrieve Lidar sensor data.
 * @author Elif Fatma Cebeci
 * @date December, 2024
 */

#ifndef LIDARSENSOR_H
#define LIDARSENSOR_H

#include "FestoRobotAPI.h"
#include <iostream>

using namespace std;

/**
 * @class LidarSensor
 * @brief A class to interface with the Lidar sensor of a robot.
 */
class LidarSensor {
private:
    float* ranges;  ///< Array to hold the range data
    FestoRobotAPI* robotAPI;  ///< Pointer to the robot API
    int rangeNumber;  ///< Number of range data points

public:
    /**
     * @brief Constructor for LidarSensor
     * @param robotAPI Pointer to the robot API
     */
    LidarSensor(FestoRobotAPI* robotAPI);

    /**
     * @brief Destructor for LidarSensor
     * This destructor releases the memory allocated for the range data.
     */
    ~LidarSensor();

    /**
     * @brief Returns the range at the specified index
     * @param index The index of the range data
     * @return The range at the specified index
     */
    double getRange(int index) const;

    /**
     * @brief Finds and returns the maximum range and its index
     * @param index Reference to an integer to store the index of the maximum range
     * @return The maximum range value
     */
    double getMax(int& index) const;

    /**
     * @brief Finds and returns the minimum range and its index
     * @param index Reference to an integer to store the index of the minimum range
     * @return The minimum range value
     */
    double getMin(int& index) const;

    /**
     * @brief Updates the range data from the Lidar sensor
     * This function retrieves the latest range data from the Lidar sensor using the robot API.
     */
    void update();

    /**
     * @brief Overloads the [] operator to return the range at a specified index
     * @param i The index of the range data
     * @return The range at the specified index
     */
    double operator[](int i);

    /**
     * @brief Calculates and returns the angle for a given index
     * @param i The index of the range data
     * @return The angle corresponding to the specified index
     */
    double getAngle(int i) const;

    /**
     * @brief Returns the number of ranges from the Lidar sensor
     * @return The number of range data points
     */
    int getRangeNum() const;
};

#endif  // LIDARSENSOR_H
