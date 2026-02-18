/**
 * @file Mapper.cpp
 * @brief Implements the Mapper class methods for map management.
 * @author R�meysa �elik (152120211125@ogrenci.ogu.edu.tr)
 * @date December, 2024
 */

#include "Mapper.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

/**
 * @brief Constructor for the Mapper class.
 * @param gridSizeX Number of grid cells in the X direction.
 * @param gridSizeY Number of grid cells in the Y direction.
 * @param cellSize The size of each grid cell.
 * @param controller Pointer to the robot controller.
 * @param lidar Pointer to the Lidar sensor.
 */
Mapper::Mapper(int gridSizeX, int gridSizeY, double cellSize, RobotControler* controller, LidarSensor* lidar)
    : map(gridSizeX, gridSizeY, cellSize), controller(controller), lidar(lidar) {}

/**
 * @brief Updates the map using data from the Lidar sensor.
 */
void Mapper::updateMap() {
    lidar->update();  ///< Updates the Lidar sensor data.
    const Pose& robotPose = controller->getPose(); ///< Retrieves the current pose of the robot.

    // Iterate through Lidar data and calculate the position of obstacles
    for (int i = 0; i < lidar->getRangeNum(); ++i) {
        double distance = lidar->getRange(i);

        if (distance <= 0) {
            continue; ///< Skip invalid distance readings.
        }

        // Convert Lidar angle to radians and calculate global x and y coordinates
        double angleInRadians = (robotPose.getTh() + lidar->getAngle(i)) * M_PI / 180.0;
        double x = robotPose.getX() + distance * cos(angleInRadians);
        double y = robotPose.getY() + distance * sin(angleInRadians);

        // Insert the calculated point into the map
        map.insertPoint(Point(x, y));
    }
}

/**
 * @brief Records the current map to a file.
 * @param filename The name of the file where the map will be saved.
 * @return True if the map was successfully saved, false otherwise.
 */
bool Mapper::recordMap(const string& filename) {
    ofstream file(filename); ///< Opens the file for writing.
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << " for writing!" << endl;
        return false; ///< Return false if the file cannot be opened.
    }

    // Write the map grid to the file
    for (int i = 0; i < map.getNumberX(); ++i) {
        for (int j = 0; j < map.getNumberY(); ++j) {
            file << map.getGrid(i, j) << " "; ///< Write grid values to the file.
        }
        file << endl;
    }

    file.close(); ///< Close the file.
    if (file.fail()) {
        cerr << "Error: Failed to write data to file \"" << filename << "\"." << endl;
        return false; ///< Return false if writing data fails.
    }

    // Confirm the map has been successfully recorded
    cout << "Map successfully recorded to file: " << filename << endl;
    return true;
}

/**
 * @brief Displays the current map in the console.
 */
void Mapper::showMap() {
    map.showMap(); ///< Calls the Map class method to display the map.
}
