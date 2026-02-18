/**
 * @file MainMenu.cpp
 * @brief Implementation of the MainMenu class for robot system.
 *
 * This file contains the implementation of the MainMenu class. It is responsible for displaying
 * the main menu of the robot system and providing options to the user to interact with
 * different sub-menus (Connection, Sensor, and Motion menus).
 *
 * @author Elif Fatma Cebeci (152120221123@ogrenci.ogu.edu.tr)
 * @date December, 2024
 */

#include "MainMenu.h"
#include <iostream>

using namespace std;

/**
 * @brief Constructor for MainMenu class.
 *
 * Initializes the main menu with the provided motion, sensor, and connection menus.
 *
 * @param motion Pointer to the MotionMenu object.
 * @param sensor Pointer to the SensorMenu object.
 * @param connection Pointer to the ConnectionMenu object.
 */
MainMenu::MainMenu(MotionMenu* motion, SensorMenu* sensor, ConnectionMenu* connection)
    : motionMenu(motion), sensorMenu(sensor), connectionMenu(connection), choice(0) {}

/**
 * @brief Destructor for MainMenu class.
 *
 * Cleans up the memory by deleting the dynamically allocated menu objects.
 */
MainMenu::~MainMenu() {
    delete motionMenu;
    delete sensorMenu;
    delete connectionMenu;
}

/**
 * @brief Clears the terminal screen.
 *
 * This function clears the terminal screen. The screen clearing command is
 * system-dependent; it uses "cls" for Windows and "clear" for Unix-based systems.
 */
void MainMenu::clearScreen() {
#ifdef _WIN32
    system("cls"); ///< Clear screen command for Windows.
#else
    system("clear"); ///< Clear screen command for Unix-based systems.
#endif
}

/**
 * @brief Displays the main menu and processes user input.
 *
 * The function displays the main menu options to the user and handles user input to
 * navigate to the appropriate sub-menu (Connection, Sensor, or Motion). The menu
 * continues to display until the user chooses to exit.
 */
void MainMenu::showMenu() {
    do {
        clearScreen(); ///< Clear the screen before showing the menu
        cout << "\n   Main Menu    \n";
        cout << "1. Connection Menu\n";
        cout << "2. Sensor Menu\n";
        cout << "3. Motion Menu\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            connectionMenu->displayMenu(); ///< Display the Connection Menu
            break;
        case 2:
            sensorMenu->showMenu(); ///< Display the Sensor Menu
            break;
        case 3:
            motionMenu->showMenu(); ///< Display the Motion Menu
            break;
        case 4:
            cout << "Exiting the program...\n"; ///< Exit message
            break;
        default:
            cout << "Invalid choice. Please try again.\n"; ///< Invalid choice message
        }
    } while (choice != 4); ///< Continue the loop until the user chooses to exit
}
