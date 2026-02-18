/**
 * @file RobotOperatorTest.cpp
 * @brief Test cases for the RobotOperator class.
 *
 * This file contains test cases to validate the functionality of the RobotOperator class,
 * including testing basic functionality, encryption and decryption consistency, and
 * handling of multiple operators with the same name but different access codes.
 *
 * @author Pariya Jahanbakhsh
 * @date December 2024
 */

#include <iostream>
#include <string>
#include "RobotOperator.h"

using namespace std;

/**
 * @brief Entry point for the RobotOperator test program.
 *
 * This program runs various test cases to verify the functionality of the RobotOperator class.
 *
 * @return int Returns 0 on successful execution.
 */
int main() {
    // Test Case 1: Basic Functionality
    cout << "Test Case 1: Robot Operator Test" << endl;
    RobotOperator operator1("Robo1", "Unit1", 1234);
    operator1.print();

    cout << "Checking access code with correct code (1234): ";
    if (operator1.checkAccessCode(1234)) {
        cout << "Access Granted" << endl;
    }
    else {
        cout << "Access Denied" << endl;
    }
    // Showing that access is granted after checking it
    operator1.print();

    cout << "Checking access code with incorrect code (5678): ";
    if (operator1.checkAccessCode(5678)) {
        cout << "Access Granted" << endl;
    }
    else {
        cout << "Access Denied" << endl;
    }

    // Test Case 2: Encryption and Decryption Consistency
    cout << "\nTest Case 2: Encryption and Decryption Consistency" << endl;
    RobotOperator operator2("Robo2", "Unit2", 5678);
    int decryptedCode = operator2.decryptCode();
    cout << "Decrypted code: " << decryptedCode << endl;

    if (decryptedCode == 5678) {
        cout << "Encryption and decryption are consistent." << endl;
    }
    else {
        cout << "Error: Encryption and decryption are inconsistent." << endl;
    }

    // Test Case 3: Same Name, Different Access Codes
    cout << "\nTest Case 3: Same Name, Different Access Codes" << endl;
    RobotOperator operator5("Robo3", "Unit5", 1234);
    RobotOperator operator6("Robo3", "Unit5", 5678);

    cout << "Operator 5 access state (code 1234): ";
    cout << (operator5.checkAccessCode(1234) ? "Access Granted" : "Access Denied") << endl;

    cout << "Operator 6 access state (code 5678): ";
    cout << (operator6.checkAccessCode(5678) ? "Access Granted" : "Access Denied") << endl;

    return 0;
}
