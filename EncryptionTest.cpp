/**
 * @file EncryptionTest.cpp
 * @author Pariya Jahanbakhsh
 * @contact (152120231154@ogrenci.ogu.edu.tr)
 * @date December 2024
 */

#include "Encryption.h"
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * @brief Tests the Encryption class by encrypting and decrypting sample numbers.
 * @details Validates the correctness of the `encrypt` and `decrypt` methods by ensuring the decrypted value matches the original input.
 */
static void EncryptionTest() {
    cout << "EncryptionTest:" << endl;

    // Create an instance of Encryption
    Encryption encryption;

    // Test with a 4-digit number
    int originalNumber = 1234;
    int encryptedNumber = encryption.encrypt(originalNumber);
    int decryptedNumber = encryption.decrypt(encryptedNumber);

    // Display the results
    cout << "Original Number : " << setw(4) << setfill('0') << originalNumber << endl;
    cout << "Encrypted Number: " << setw(4) << setfill('0') << encryptedNumber << endl;
    cout << "Decrypted Number: " << setw(4) << setfill('0') << decryptedNumber << endl;

    // Test with another 4-digit number
    originalNumber = 2563;
    encryptedNumber = encryption.encrypt(originalNumber);
    decryptedNumber = encryption.decrypt(encryptedNumber);

    // Display the results
    cout << "Original Number : " << setw(4) << setfill('0') << originalNumber << endl;
    cout << "Encrypted Number: " << setw(4) << setfill('0') << encryptedNumber << endl;
    cout << "Decrypted Number: " << setw(4) << setfill('0') << decryptedNumber << endl;

    cout << endl;
}

/**
 * @brief Entry point for the EncryptionTest program.
 * @return int Returns 0 on successful execution.
 */
int main() {
    EncryptionTest();
    return 0;
}

