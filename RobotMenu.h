/**
 * @file RobotMenu.h
 * @brief Header file for the RobotMenu class.
 *
 * This file defines the RobotMenu class, which manages operator login
 * and the main menu functionalities for a robot control system.
 *
 * @author Elif Fatma Cebeci (152120221123@ogrenci.ogu.edu.tr)
 * @date December, 2024
 */

#ifndef ROBOTMENU_H
#define ROBOTMENU_H

#include "OperatorLoginMenu.h"
#include "MainMenu.h"
#include <vector>
#include <string>

 /**
  * @class RobotMenu
  * @brief A class to manage the robot's main menu and operator login functionalities.
  */
class RobotMenu {
private:
    OperatorLoginMenu* loginMenu; ///< Pointer to the OperatorLoginMenu for handling operator logins.
    MainMenu* mainMenu;           ///< Pointer to the MainMenu for accessing main menu functionalities.

public:
    /**
     * @brief Constructs a RobotMenu object.
     *
     * Initializes the RobotMenu with a given MainMenu object.
     *
     * @param mainMenu Pointer to the MainMenu object to be used.
     */
    RobotMenu(MainMenu* mainMenu);

    /**
     * @brief Destructor for the RobotMenu class.
     *
     * Frees the allocated memory for loginMenu and mainMenu.
     */
    ~RobotMenu();

    /**
     * @brief Adds operators to the system.
     *
     * Allows the user to input and add new operators to the system.
     */
    void addOperators();

    /**
     * @brief Runs the RobotMenu.
     *
     * Manages the main loop of the menu, allowing interaction with the robot system.
     */
    void run();
};

#endif // ROBOTMENU_H
