/**
 * @file Encryption.cpp
 * @brief Implementation of the Encryption class.
 * @author Pariya Jahanbakhsh
 * @date December 2024
 */

#include "Encryption.h"

 /**
  * @brief Encrypts a 4-digit number using a simple encryption algorithm.
  *
  * This function extracts the digits of the given number, applies an
  * encryption formula, and rearranges the digits to produce an encrypted number.
  *
  * @param number The 4-digit number to be encrypted.
  * @return The encrypted number.
  */
int Encryption::encrypt(int number) {
    // Extract digits
    int digit1 = number / 1000;
    int digit2 = (number / 100) % 10;
    int digit3 = (number / 10) % 10;
    int digit4 = number % 10;

    // Encryption algorithm
    digit1 = (digit1 + 7) % 10;
    digit2 = (digit2 + 7) % 10;
    digit3 = (digit3 + 7) % 10;
    digit4 = (digit4 + 7) % 10;

    // Swap and combine digits to form the encrypted number
    int encryptedNumber = digit3 * 1000 + digit4 * 100 + digit1 * 10 + digit2;
    return encryptedNumber;
}

/**
 * @brief Decrypts a 4-digit encrypted number back to its original form.
 *
 * This function extracts the digits of the encrypted number, applies a
 * decryption formula, and rearranges the digits to produce the original number.
 *
 * @param number The encrypted 4-digit number to be decrypted.
 * @return The original number before encryption.
 */
int Encryption::decrypt(int number) {
    // Extract digits
    int digit1 = number / 1000;
    int digit2 = (number / 100) % 10;
    int digit3 = (number / 10) % 10;
    int digit4 = number % 10;

    // Decryption algorithm
    digit1 = (digit1 + 3) % 10;
    digit2 = (digit2 + 3) % 10;
    digit3 = (digit3 + 3) % 10;
    digit4 = (digit4 + 3) % 10;

    // Swap and combine digits to form the decrypted number
    int decryptedNumber = digit3 * 1000 + digit4 * 100 + digit1 * 10 + digit2;
    return decryptedNumber;
}
