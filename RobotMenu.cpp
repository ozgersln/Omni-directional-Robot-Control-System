/**
 * @file RobotMenu.cpp
 * @brief Implementation of the RobotMenu class
 * @details This class handles the interaction with the user to add operators and manage the login process.
 */

#include "RobotMenu.h"
#include <iostream>

using namespace std;

/**
 * @brief Constructor for the RobotMenu class
 *
 * @param mainMenu Pointer to the MainMenu object
 */
RobotMenu::RobotMenu(MainMenu* mainMenu) {
    this->mainMenu = mainMenu;
    loginMenu = nullptr; // Initialize loginMenu to nullptr
}

/**
 * @brief Destructor for the RobotMenu class
 *
 * This destructor deletes the loginMenu object to free memory.
 */
RobotMenu::~RobotMenu() {
    delete loginMenu;
}

/**
 * @brief Function to add operators
 *
 * This function prompts the user to enter the number of operators and their details.
 * It then creates an OperatorLoginMenu object and manages the login process.
 */
void RobotMenu::addOperators() {
    // Collect operator information from the user
    vector<RobotOperator> operators;
    int numOperators;

    cout << "How many operators would you like to add? ";
    cin >> numOperators;

    for (int i = 0; i < numOperators; ++i) {
        string name, surname;
        int accessCode;

        cout << "Enter the name of operator " << i + 1 << ": ";
        getline(cin, name);

        cout << "Enter the surname of operator " << i + 1 << ": ";
        getline(cin, surname);

        cout << "Enter the access code of operator " << i + 1 << " (4 digits): ";
        cin >> accessCode;

        operators.emplace_back(name, surname, accessCode);
    }

    // Create OperatorLoginMenu object
    OperatorLoginMenu loginMenu(operators);

    // Ask the user to test login
    char choice;
    do {
        cout << "\nWould you like to enter the login menu? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            loginMenu.showLoginMenu();
            if (loginMenu.isLoggedIn()) { mainMenu->showMenu(); }
        }
    } while (choice == 'y' || choice == 'Y');

    // Test logout functionality
    cout << "\nLogout test:\n";
    loginMenu.logout();
}

/**
 * @brief Run the RobotMenu
 *
 * This function starts the process of adding operators and managing the login process.
 */
void RobotMenu::run() {
    addOperators();
}
