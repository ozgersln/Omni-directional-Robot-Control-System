/**
 * @file MapperTest.cpp
 * @brief Tests the functionality of the Mapper class.
 * @author R�meysa �elik (152120211125@ogrenci.ogu.edu.tr)
 * @date December, 2024
 */

#include "Mapper.h"
#include "RobotControler.h"
#include "LidarSensor.h"
#include "FestoRobotAPI.h"
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

/**
 * @brief Runs a series of tests on the Mapper class.
 */
void testMapper() {
    FestoRobotAPI robotAPI; ///< Instance of the robot API.

    Pose initialPose(0.0, 0.0, 0.0); ///< Robot's initial position.
    RobotControler robotController(&initialPose, &robotAPI); ///< Robot controller instance.
    LidarSensor lidarSensor(&robotAPI); ///< Lidar sensor instance.

    assert(robotController.connectRobot() && "Failed to connect to the robot!");

    Mapper mapper(20, 20, 1.0, &robotController, &lidarSensor); ///< Mapper instance with a 20x20 grid and 1.0 cell size.

    /**
     * @test Test 1: Update the map using the Mapper class.
     */
    cout << "Updating the map..." << endl;
    mapper.updateMap();

    cout << "Map:" << endl;
    mapper.showMap();

    /**
     * @test Test 2: Save the map to a file and verify success.
     */
    string filename = "test_map.txt";
    bool isRecorded = mapper.recordMap(filename);
    assert(isRecorded && "Failed to record the map to file!");
    cout << "Map successfully saved to " << filename << endl;

    /**
     * @test Test 3: Verify the map contents in the saved file.
     */
    ifstream file(filename);
    assert(file.is_open() && "Failed to open the map file!");

    string line;
    bool isMapFound = false;
    while (getline(file, line)) {
        if (line.find("Map") != string::npos) {
            isMapFound = true;
        }
    }
    assert(isMapFound && "Map not found in the file!");
    file.close();

    /**
     * @test Test 4: Move the robot, update the map, and verify the updates.
     */
    cout << "Moving the robot and updating the map..." << endl;
    robotController.moveForward();
    robotController.moveRight();
    mapper.updateMap();

    cout << "Updated Map:" << endl;
    mapper.showMap();

    robotController.stop();
    assert(robotController.disconnectRobot() && "Failed to disconnect the robot!");

    cout << "All tests passed successfully!" << endl;
}

/**
 * @brief Main function to execute the Mapper tests.
 * @return Exit status of the program.
 */
int main() {
    testMapper(); ///< Execute the Mapper tests.
    return 0;
}
