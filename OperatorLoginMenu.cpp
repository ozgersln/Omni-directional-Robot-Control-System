/**
 * @file OperatorLoginMenu.cpp
 * @brief Implementation of the OperatorLoginMenu class for managing operator login functionality.
 * @details This class provides an interface for operators to log in, authenticate, and log out of the system.
 * @author Pariya Jahanbakhsh
 * @contact (152120231154@ogrenci.ogu.edu.tr)
 * @date December 2024
 */

#include "OperatorLoginMenu.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Constructs an OperatorLoginMenu object with a given list of operators.
 * @param operatorList The list of operators available for login.
 */
OperatorLoginMenu::OperatorLoginMenu(const std::vector<RobotOperator>& operatorList)
    : operators(operatorList), loggedInOperator(nullptr) {}

/**
 * @brief Finds an operator by their first name.
 * @param name The first name of the operator to search for.
 * @return A pointer to the matching RobotOperator, or nullptr if not found.
 */
RobotOperator* OperatorLoginMenu::findOperatorByName(const std::string& name) {
    for (auto& op : operators) {
        if (op.getName() == name) {
            return &op;
        }
    }
    return nullptr;
}

/**
 * @brief Finds an operator by their surname.
 * @param surname The surname of the operator to search for.
 * @return A pointer to the matching RobotOperator, or nullptr if not found.
 */
RobotOperator* OperatorLoginMenu::findOperatorBySurname(const std::string& surname) {
    for (auto& op : operators) {
        if (op.getSurname() == surname) {
            return &op;
        }
    }
    return nullptr;
}

/**
 * @brief Displays the login menu and handles the login process.
 * @details Prompts the user for their name, surname, and access code to authenticate.
 */
void OperatorLoginMenu::showLoginMenu() {
    string name, surname;
    string accessCodeInput;

    cout << "-----------------------------------------------\n";
    cout << "Welcome to Webots Robot Control Application\n";
    cout << "-----------------------------------------------\n";
    cout << "Operator Login Menu\n";
    cout << "--------------------\n";

    cout << "Please enter your first name: ";
    getline(cin, name);

    RobotOperator* operatorByName = findOperatorByName(name);
    if (!operatorByName) {
        cout << "Error: Operator with this name not found.\n";
        return;
    }

    cout << "Please enter your surname: ";
    getline(cin, surname);

    RobotOperator* operatorBySurname = findOperatorBySurname(surname);
    if (!operatorBySurname || operatorByName != operatorBySurname) {
        cout << "Error: Operator with this name and surname not found.\n";
        return;
    }

    RobotOperator* operatorToLogin = operatorByName;

    do {
        cout << "Please enter your access code: ";

        // Securely capture access code
        char ch;
        accessCodeInput.clear();
        while ((ch = getchar()) != '\n' && ch != EOF) {
            if (isdigit(ch)) {
                accessCodeInput += ch;
                cout << '*'; // Mask input
            }
        }
        cout << endl;

        if (accessCodeInput.length() != 4) {
            cout << "Error: Access code must be a 4-digit integer. Please try again.\n";
        }
    } while (accessCodeInput.length() != 4);

    int accessCode;
    try {
        accessCode = stoi(accessCodeInput);
    }
    catch (const std::exception&) {
        cout << "Error: Invalid access code input.\n";
        return;
    }

    if (operatorToLogin->checkAccessCode(accessCode)) {
        loggedInOperator = operatorToLogin;
        cout << "Operator authorized. Access granted.\n";
        displayLoggedInOperatorDetails();
    }
    else {
        cout << "Error: Invalid access code.\n";
    }
}

/**
 * @brief Logs out the currently logged-in operator.
 */
void OperatorLoginMenu::logout() {
    if (isLoggedIn()) {
        cout << "Operator " << loggedInOperator->getName() << " " << loggedInOperator->getSurname() << " logged out.\n";
        loggedInOperator = nullptr;
    }
    else {
        cout << "No operator is currently logged in.\n";
    }
}

/**
 * @brief Checks if any operator is currently logged in.
 * @return True if an operator is logged in, false otherwise.
 */
bool OperatorLoginMenu::isLoggedIn() const {
    return loggedInOperator != nullptr;
}

/**
 * @brief Displays the details of the currently logged-in operator.
 */
void OperatorLoginMenu::displayLoggedInOperatorDetails() const {
    if (isLoggedIn()) {
        cout << "Operator Information:\n";
        cout << "Name: " << loggedInOperator->getName() << "\n";
        cout << "Surname: " << loggedInOperator->getSurname() << "\n";
        cout << "Access State: Granted\n";
    }
    else {
        cout << "No operator is logged in.\n";
    }
}
