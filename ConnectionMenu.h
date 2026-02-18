/**
 * @file ConnectionMenu.h
 * @brief Declaration of the ConnectionMenu class.
 *
 * This header defines the ConnectionMenu class, which provides a menu interface
 * for controlling a robot using a RobotControler object.
 *
 * @author Pariya Jahanbakhsh
 * @date December 2024
 */

#ifndef CONNECTIONMENU_H
#define CONNECTIONMENU_H

#include "RobotControler.h"

 /**
  * @class ConnectionMenu
  * @brief A class to manage a connection menu for robot control.
  *
  * The ConnectionMenu class provides functionality to display a menu and handle
  * user-selected options for interacting with a robot through a RobotControler object.
  */
class ConnectionMenu {
private:
    RobotControler* robotController; ///< Pointer to the RobotControler object.

public:
    /**
     * @brief Constructor for the ConnectionMenu class.
     *
     * Initializes the menu with a given RobotControler object.
     *
     * @param controller A pointer to the RobotControler object to be used by the menu.
     */
    ConnectionMenu(RobotControler* controller);

    /**
     * @brief Displays the connection menu options to the user.
     */
    void displayMenu();

    /**
     * @brief Handles the user-selected menu option.
     *
     * @param choice The user's choice as an integer.
     */
    void handleOption(int choice);
};

#endif // CONNECTIONMENU_H