/**
 * @file OperatorLoginMenuTest.cpp
 * @brief Contains the test function for the OperatorLoginMenu class.
 * @author Elif Fatma Cebeci  (152120221123@ogrenci.ogu.edu.tr)
 * @date December, 2024
 */

#include "OperatorLoginMenu.h"
#include "RobotOperator.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief Test function for the OperatorLoginMenu class.
 *
 * This function allows users to add operators, test the login functionality,
 * and verify the logout functionality of the OperatorLoginMenu class.
 */
void testOperatorLoginMenu() {
    // Vector to hold operator data
    vector<RobotOperator> operators;
    int numOperators;

    // Get the number of operators from the user
    cout << "Ka� operat�r eklemek istiyorsunuz? ";
    cin >> numOperators;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    // Collect operator details
    for (int i = 0; i < numOperators; ++i) {
        string name, surname;
        int accessCode;

        cout << "Operat�r " << i + 1 << " ad�n� girin: ";
        getline(cin, name);

        cout << "Operat�r " << i + 1 << " soyad�n� girin: ";
        getline(cin, surname);

        cout << "Operat�r " << i + 1 << " eri�im kodunu girin (4 basamakl�): ";
        cin >> accessCode;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        operators.emplace_back(name, surname, accessCode);
    }

    // Create an OperatorLoginMenu instance
    OperatorLoginMenu loginMenu(operators);

    // Allow user to test the login functionality
    char choice;
    do {
        cout << "\nGiri� men�s�ne girmek ister misiniz? (e/h): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        if (choice == 'e' || choice == 'E') {
            /**
             * @brief Test login menu functionality.
             *
             * Calls the showLoginMenu function to test the operator login process.
             */
            loginMenu.showLoginMenu();
        }
    } while (choice == 'e' || choice == 'E');

    // Test logout functionality
    cout << "\n��k�� yapma testi:\n";
    /**
     * @brief Test logout functionality.
     *
     * Calls the logout function to ensure it clears the current operator session.
     */
    loginMenu.logout();
}

/**
 * @brief Main function for testing the OperatorLoginMenu.
 *
 * The main function invokes the test function to demonstrate the
 * functionality of the OperatorLoginMenu class.
 *
 * @return 0 on successful execution.
 */
int main() {
    testOperatorLoginMenu();
    return 0;
}
