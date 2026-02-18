/**
 * @file RobotOperator.h
 * @brief Declaration of the RobotOperator class, which manages robot operator information and access control.
 * @author Pariya Jahanbakhsh
 * @contact (152120231154@ogrenci.ogu.edu.tr)
 * @date December 2024
 */

#ifndef ROBOTOPERATOR_H
#define ROBOTOPERATOR_H

#include <string>
#include "Encryption.h"

 /**
  * @class RobotOperator
  * @brief A class to represent a robot operator and manage access control using encrypted access codes.
  */
class RobotOperator {
private:
    std::string name;       /**< Operator's name */
    std::string surname;    /**< Operator's surname */
    unsigned int accessCode; /**< Encrypted access code */
    bool accessState;       /**< Access state (true if access granted, false otherwise) */

public:
    /**
     * @brief Constructor for the RobotOperator class.
     * @param name The operator's first name.
     * @param surname The operator's last name.
     * @param code The initial access code to be encrypted.
     */
    RobotOperator(const std::string& name, const std::string& surname, int code);

    /**
     * @brief Encrypts the access code using the Encryption class.
     * @param code The access code to encrypt.
     */
    void encryptCode(int code);

    /**
     * @brief Decrypts the access code using the Encryption class.
     * @return The decrypted access code.
     */
    int decryptCode() const;

    /**
     * @brief Checks if the entered access code matches the encrypted access code.
     * @param enteredCode The access code entered by the user.
     * @return True if the entered code matches, otherwise false.
     */
    bool checkAccessCode(int enteredCode);

    /**
     * @brief Prints the operator's information, including name, surname, and access state.
     */
    void print() const;

    /**
     * @brief Retrieves the operator's first name.
     * @return The operator's first name as a string.
     */
    std::string getName() const;

    /**
     * @brief Retrieves the operator's last name.
     * @return The operator's last name as a string.
     */
    std::string getSurname() const;
};

#endif // ROBOTOPERATOR_H


