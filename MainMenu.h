
/**
 * @file MainMenu.h
 * @brief Declaration of the MainMenu class for managing the main menu of the robot system.
 *
 * This header file defines the MainMenu class, which provides functionality to display
 * and manage the robot's main menu, integrating MotionMenu, SensorMenu, and ConnectionMenu.
 *
 * @author Elif Fatma Cebeci (152120221123@ogrenci.ogu.edu.tr)
 * @date December, 2024
 */

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "MotionMenu.h"
#include "SensorMenu.h"
#include "ConnectionMenu.h"

 /**
  * @class MainMenu
  * @brief Class representing the main menu of the robot system.
  *
  * The MainMenu class provides methods to display the main menu and handle user interactions
  * by integrating submenus such as MotionMenu, SensorMenu, and ConnectionMenu.
  */
class MainMenu {
private:
    MotionMenu* motionMenu;       ///< Pointer to MotionMenu object for motion-related operations
    SensorMenu* sensorMenu;       ///< Pointer to SensorMenu object for sensor-related operations
    ConnectionMenu* connectionMenu; ///< Pointer to ConnectionMenu object for connection-related operations
    int choice;                   ///< User's choice in the main menu

    /**
     * @brief Clears the console screen.
     *
     * This private utility function clears the screen to improve the readability of menu displays.
     */
    void clearScreen();

public:
    /**
     * @brief Constructor for the MainMenu class.
     *
     * Initializes the MainMenu object with references to MotionMenu, SensorMenu, and ConnectionMenu.
     *
     * @param motion Pointer to the MotionMenu object.
     * @param sensor Pointer to the SensorMenu object.
     * @param connection Pointer to the ConnectionMenu object.
     */
    MainMenu(MotionMenu* motion, SensorMenu* sensor, ConnectionMenu* connection);

    /**
     * @brief Destructor for the MainMenu class.
     *
     * Ensures proper cleanup of any resources held by the MainMenu.
     */
    ~MainMenu();

    /**
     * @brief Displays the main menu and handles user interactions.
     *
     * This method provides the user interface for selecting and interacting with the submenus.
     */
    void showMenu();
};

#endif // MAIN_MENU_H

