/**
 * @file OperatorLoginMenu.h
 * @brief Declaration of the OperatorLoginMenu class, which manages operator login and logout functionality.
 * @details This class allows managing multiple robot operators and provides login/logout features for secure access.
 * @author Pariya Jahanbakhsh
 * @contact (152120231154@ogrenci.ogu.edu.tr)
 * @date December 2024
 */

#ifndef OPERATORLOGINMENU_H
#define OPERATORLOGINMENU_H

#include "RobotOperator.h"
#include <vector>
#include <string>

 /**
  * @class OperatorLoginMenu
  * @brief A class to manage the login menu for robot operators.
  */
class OperatorLoginMenu {
private:
    std::vector<RobotOperator> operators; /**< List of available operators */
    RobotOperator* loggedInOperator;      /**< Pointer to the currently logged-in operator */

    /**
     * @brief Finds an operator by their first name.
     * @param name The first name of the operator to find.
     * @return A pointer to the RobotOperator if found, otherwise nullptr.
     */
    RobotOperator* findOperatorByName(const std::string& name);

    /**
     * @brief Finds an operator by their surname.
     * @param surname The surname of the operator to find.
     * @return A pointer to the RobotOperator if found, otherwise nullptr.
     */
    RobotOperator* findOperatorBySurname(const std::string& surname);

public:
    /**
     * @brief Constructor for the OperatorLoginMenu class.
     * @param operatorList A vector of RobotOperator objects to initialize the menu.
     */
    OperatorLoginMenu(const std::vector<RobotOperator>& operatorList);

    /**
     * @brief Displays the login menu and handles login interactions.
     */
    void showLoginMenu();

    /**
     * @brief Logs out the currently logged-in operator.
     */
    void logout();

    /**
     * @brief Checks if an operator is currently logged in.
     * @return True if an operator is logged in, otherwise false.
     */
    bool isLoggedIn() const;

    /**
     * @brief Displays details of the currently logged-in operator.
     */
    void displayLoggedInOperatorDetails() const;
};

#endif // OPERATORLOGINMENU_H
