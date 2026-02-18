/**
 * @file ConnectionMenu.cpp
 * @brief Implementation of the ConnectionMenu class for managing robot connection options.
 * @details This class provides a simple menu interface for connecting and disconnecting a robot via the RobotControler class.
 * @author Pariya Jahanbakhsh
 * @contact (152120231154@ogrenci.ogu.edu.tr)
 * @date December 2024
 */

#include "ConnectionMenu.h"
#include <iostream>

using namespace std;

/**
 * @brief Constructs a ConnectionMenu object with the given RobotControler.
 * @param controller A pointer to the RobotControler instance.
 */
ConnectionMenu::ConnectionMenu(RobotControler* controller) : robotController(controller) {}

/**
 * @brief Displays the connection menu, allowing the user to choose options to connect or disconnect the robot.
 */
void ConnectionMenu::displayMenu() {
    int choice = 0;

    while (choice != 3) {
        cout << "\nConnection Menu\n";
        cout << "1. Connect Robot\n";
        cout << "2. Disconnect Robot\n";
        cout << "3. Back\n";
        cout << "Choose one: ";
        cin >> choice;

        handleOption(choice);
    }
}

/**
 * @brief Handles the user's menu choice.
 * @param choice The user's menu selection.
 * @details Performs the appropriate action based on the user's input:
 * - Option 1: Attempt to connect the robot.
 * - Option 2: Attempt to disconnect the robot.
 * - Option 3: Return to the previous menu.
 * - Invalid input: Display an error message.
 */
void ConnectionMenu::handleOption(int choice) {
    switch (choice) {
    case 1:
        if (robotController->connectRobot()) {
            cout << "Robot connected successfully.\n";
        }
        else {
            cout << "Failed to connect the robot.\n";
        }
        break;
    case 2:
        if (robotController->disconnectRobot()) {
            cout << "Robot disconnected successfully.\n";
        }
        else {
            cout << "Failed to disconnect the robot.\n";
        }
        break;
    case 3:
        cout << "Returning to the previous menu...\n";
        break;
    default:
        cout << "Invalid option. Please try again.\n";
    }
}
