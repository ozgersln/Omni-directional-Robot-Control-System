/**
 * @file MotionMenu.h
 * @brief Header file for the MotionMenu class, providing an interface for robot motion commands through a menu-based system.
 * @author 
 * @date December 2024
 */

#ifndef MOTIONMENU_H
#define MOTIONMENU_H

#include "RobotControler.h"
#include "SafeNavigation.h"

/**
 * @class MotionMenu
 * @brief Manages a menu interface for controlling the robot's motions and navigation.
 */
class MotionMenu {
private:
    RobotControler* Control;   /**< Pointer to the RobotControler object for controlling the robot. */
    int choice;                /**< Variable to store the user's menu choice. */
    SafeNavigation* SafeNav;   /**< Pointer to the SafeNavigation object for safe movement. */

public:
    /**
     * @brief Constructor for the MotionMenu class.
     * @param control Pointer to the RobotControler object.
     * @param safeNav Pointer to the SafeNavigation object.
     * @param Choice Initial choice for the menu.
     */
    MotionMenu(RobotControler* control, SafeNavigation* safeNav, int Choice);

    /**
     * @brief Destructor for the MotionMenu class.
     */
    ~MotionMenu();

    /**
     * @brief Displays the motion menu and allows the user to select commands.
     */
    void showMenu();

    /**
     * @brief Executes the selected menu option to control the robot.
     */
    void ExecuteChoice();
};

#endif // MOTIONMENU_H
