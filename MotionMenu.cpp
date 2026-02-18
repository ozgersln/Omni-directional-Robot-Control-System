/**
 * @file MotionMenu.cpp
 * @brief Implementation of the MotionMenu class, providing a user interface for robot motion commands.
 * @author Elif Fatma Cebeci
 * @date December 2024
 */

#include "MotionMenu.h"
#include <iostream>
using namespace std;

/**
 * @brief Constructor for the MotionMenu class.
 * @param control Pointer to the RobotControler object.
 * @param safeNav Pointer to the SafeNavigation object.
 * @param Choice Initial menu choice.
 */
MotionMenu::MotionMenu(RobotControler* control, SafeNavigation* safeNav, int Choice)
    : Control(control), SafeNav(safeNav), choice(Choice) {}

/**
 * @brief Destructor for the MotionMenu class.
 */
MotionMenu::~MotionMenu() {}

/**
 * @brief Displays the motion menu and processes user input for motion commands.
 */
void MotionMenu::showMenu() {
    do {
        cout << endl;
        cout << "    Motion Menu    \n";
        cout << "1. Move forward" << endl;
        cout << "2. Move backward" << endl;
        cout << "3. Move left" << endl;
        cout << "4. Move right" << endl;
        cout << "5. Safe Move forward" << endl;
        cout << "6. Safe Move backward" << endl;
        cout << "7. Turn left" << endl;
        cout << "8. Turn right" << endl;
        cout << "9. Move distance" << endl;
        cout << "10. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        ExecuteChoice();
    } while (choice != 10);
}

/**
 * @brief Executes the selected motion command based on the user's choice.
 */
void MotionMenu::ExecuteChoice() {
    // Check if the robot is off
    if (!Control->Status()) {
        cout << "The robot is off." << endl;
        return;
    }
    switch (choice) {
    case 1:
        Control->moveForward();
        cout << "Robot moved forward!" << endl;
        Sleep(2000);
        Control->stop();
        break;
    case 2:
        Control->moveBackward();
        cout << "Robot moved backward!" << endl;
        Sleep(2000);
        Control->stop();
        break;
    case 3:
        Control->moveLeft();
        cout << "Robot moved left!" << endl;
        Sleep(2000);
        Control->stop();
        break;
    case 4:
        Control->moveRight();
        cout << "Robot moved right!" << endl;
        Sleep(2000);
        Control->stop();
        break;
    case 5:
        SafeNav->moveForwardSafe();
        cout << "Safe Move Robot activated!" << endl;
        break;
    case 6:
        SafeNav->moveBackwardSafe();
        cout << "Safe Move Robot activated!" << endl;
        break;
    case 7:
        Control->turnLeft();
        cout << "Robot turned left!" << endl;
        Sleep(1000);
        Control->stop();
        break;
    case 8:
        Control->turnRight();
        cout << "Robot turned right!" << endl;
        Sleep(1000);
        Control->stop();
        break;
    case 9: {
        double distance;
        cout << "Enter the distance to move: ";
        cin >> distance;
        for (int i = 0; i < distance; ++i) {
            Control->moveForward();
            Sleep(2000);
            Control->stop();
        }
        cout << "Robot moved " << distance << " units." << endl;
        break;
    }
    case 10:
        cout << "Exiting the menu." << endl;
        break;
    default:
        cout << "Invalid choice! Please select a valid option." << endl;
        break;
    }
}
