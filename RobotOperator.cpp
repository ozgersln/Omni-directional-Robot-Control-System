/**
 * @file RobotOperator.cpp
 * @brief Implementation of the RobotOperator class, which manages robot operator information and access control.
 * @author Pariya Jahanbakhsh
 * @contact (152120231154@ogrenci.ogu.edu.tr)
 * @date December 2024
 */

#include "RobotOperator.h"
#include <iostream>
#include "Encryption.h"

using namespace std;

/**
 * @brief Constructor for the RobotOperator class.
 * @param name The operator's first name.
 * @param surname The operator's last name.
 * @param code The initial access code to be encrypted.
 */
RobotOperator::RobotOperator(const string& name, const string& surname, int code)
    : name(name), surname(surname), accessState(false) {
    encryptCode(code); // Encrypt and store the access code
}

/**
 * @brief Encrypts the access code using the Encryption class.
 * @param code The access code to encrypt. Must be a 4-digit integer.
 */
void RobotOperator::encryptCode(int code) {
    if (code < 1000 || code > 9999) {
        cerr << "Error: Access code must be a 4-digit integer.\n";
        accessCode = 0; // Set to an invalid state
        return;
    }
    Encryption encryption;
    accessCode = encryption.encrypt(code);
}

/**
 * @brief Decrypts the access code using the Encryption class.
 * @return The decrypted access code, or -1 if decryption fails.
 */
int RobotOperator::decryptCode() const {
    Encryption encryption;
    int decryptedCode = encryption.decrypt(accessCode);

    if (decryptedCode == -1) {
        cerr << "Error: Failed to decrypt access code.\n";
        return -1; // Return error code
    }

    return decryptedCode;
}

/**
 * @brief Checks if the entered access code matches the encrypted access code.
 * @param enteredCode The access code entered by the user. Must be a 4-digit integer.
 * @return True if the entered code matches the encrypted code, otherwise false.
 */
bool RobotOperator::checkAccessCode(int enteredCode) {
    if (enteredCode < 1000 || enteredCode > 9999) {
        cerr << "Error: Entered code must be a 4-digit integer.\n";
        return false;
    }

    bool isCorrect = enteredCode == decryptCode();
    accessState = isCorrect; // Update accessState directly

    return isCorrect;
}

/**
 * @brief Prints the operator's information, including name, surname, and access state.
 */
void RobotOperator::print() const {
    cout << "Operator: " << name << " " << surname << "\n";
    cout << "Access State: " << (accessState ? "Granted" : "Denied") << "\n";
}

/**
 * @brief Retrieves the operator's first name.
 * @return The operator's first name as a string.
 */
std::string RobotOperator::getName() const {
    return name;
}

/**
 * @brief Retrieves the operator's last name.
 * @return The operator's last name as a string.
 */
std::string RobotOperator::getSurname() const {
    return surname;
}