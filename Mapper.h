/**
 * @file Mapper.h
 * @brief Defines the Mapper class for managing map updates and recordings.
 * @author R�meysa �elik (152120211125@ogrenci.ogu.edu.tr)
 * @date December, 2024
 */

#ifndef MAPPER_H
#define MAPPER_H

#include "Map.h"
#include "LidarSensor.h"
#include "RobotControler.h"
#include <vector>
#include <string>

using namespace std;

/**
 * @class Mapper
 * @brief Handles mapping functionality, including updates and saving map data.
 */
class Mapper {
private:
    Map map; ///< Represents the map of the environment.
    RobotControler* controller; ///< Pointer to the robot controller.
    LidarSensor* lidar; ///< Pointer to the Lidar sensor.

public:
    /**
     * @brief Constructs a Mapper object.
     * @param gridSizeX Number of grid cells in the X direction.
     * @param gridSizeY Number of grid cells in the Y direction.
     * @param cellSize The size of each grid cell.
     * @param controller Pointer to the robot controller.
     * @param lidar Pointer to the Lidar sensor.
     */
    Mapper(int gridSizeX, int gridSizeY, double cellSize, RobotControler* controller, LidarSensor* lidar);

    /**
     * @brief Updates the map using data from the Lidar sensor.
     */
    void updateMap();

    /**
     * @brief Records the current map to a file.
     * @param filename The name of the file where the map will be saved.
     * @return True if the map was successfully saved, false otherwise.
     */
    bool recordMap(const string& filename);

    /**
     * @brief Displays the current map.
     */
    void showMap();
};

#endif // MAPPER_H
