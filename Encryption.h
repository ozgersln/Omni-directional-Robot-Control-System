/**
 * @file Encryption.h
 * @brief Declaration of the Encryption class.
 *
 * This header defines the Encryption class, which provides methods to encrypt
 * and decrypt 4-digit integers using a simple algorithm.
 *
 * @author Pariya Jahanbakhsh
 * @date December 2024
 */

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

 /**
  * @class Encryption
  * @brief A class for encrypting and decrypting 4-digit integers.
  *
  * The Encryption class provides methods to apply a simple algorithm
  * for encrypting and decrypting 4-digit integers.
  */
class Encryption {
public:
    /**
     * @brief Encrypts a 4-digit integer.
     *
     * This method applies an encryption algorithm to rearrange and transform
     * the digits of the input number.
     *
     * @param number The 4-digit integer to be encrypted.
     * @return The encrypted 4-digit integer.
     */
    int encrypt(int number);

    /**
     * @brief Decrypts a 4-digit encrypted integer.
     *
     * This method reverses the encryption algorithm to restore the original
     * 4-digit number from its encrypted form.
     *
     * @param number The encrypted 4-digit integer to be decrypted.
     * @return The original 4-digit integer.
     */
    int decrypt(int number);
};

#endif // ENCRYPTION_H


