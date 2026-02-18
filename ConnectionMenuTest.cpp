/**

 * @author Pariya Jahanbakhsh
 * @contact (152120231154@ogrenci.ogu.edu.tr)
 * @date December 2024
 */

#include "ConnectionMenu.h"
#include "RobotControler.h"
#include "Pose.h"
#include "FestoRobotAPI.h"
#include <iostream>

using namespace std;

/**
 * @brief Main function to test the ConnectionMenu and RobotController functionality.
 * @return int Returns 0 on successful execution.
 */
int main() {
    // Create objects needed for the RobotController
    Pose* position = new Pose();                   /**< Robot's initial pose */
    FestoRobotAPI* robotAPI = new FestoRobotAPI(); /**< Mocked robot API object */
    RobotControler robotController(position, robotAPI);

    // Create a ConnectionMenu instance
    ConnectionMenu connectionMenu(&robotController);

    // Display the connection menu for testing
    cout << "=== Connection Menu Test ===" << endl;
    connectionMenu.displayMenu();

    // Check connection status
    if (robotController.connectRobot()) {
        cout << "[TEST PASSED] Robot connected successfully.\n";
    }
    else {
        cout << "[TEST FAILED] Robot failed to connect.\n";
    }

    // Disconnect the robot
    if (robotController.disconnectRobot()) {
        cout << "[TEST PASSED] Robot disconnected successfully.\n";
    }
    else {
        cout << "[TEST FAILED] Robot failed to disconnect.\n";
    }

    // Clean up
    delete position;
    delete robotAPI;

    return 0;
}