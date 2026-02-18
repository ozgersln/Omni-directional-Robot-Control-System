/**
 * @file Record.h
 * @brief Header file for the Record class, managing file operations.
 * @author R�meysa �elik (152120211125@ogrenci.ogu.edu.tr)
 * @date December, 2024
 */

#ifndef RECORD_H
#define RECORD_H

#include <fstream>
#include <string>

using namespace std;

/**
 * @class Record
 * @brief Provides file handling functionalities, including read and write operations.
 */
class Record {
private:
    string fileName; ///< Name of the file to be managed.
    fstream file;    ///< File stream object for file operations.

public:
    /**
     * @brief Opens the file associated with the Record instance.
     * @return True if the file is opened successfully, false otherwise.
     */
    bool openFile();

    /**
     * @brief Closes the currently open file.
     * @return True if the file is closed successfully, false otherwise.
     */
    bool closeFile();

    /**
     * @brief Sets the name of the file to be managed.
     * @param name The name of the file.
     */
    void setFileName(const string& name);

    /**
     * @brief Reads a single line from the file.
     * @return The line read from the file as a string.
     */
    string readLine();

    /**
     * @brief Writes a single line to the file.
     * @param str The string to be written to the file.
     * @return True if the write operation is successful, false otherwise.
     */
    bool writeLine(const string& str);

    /**
     * @brief Overloads the output stream operator for the Record class.
     * @param os Output stream reference.
     * @param record Reference to the Record instance.
     * @return Modified output stream reference.
     */
    friend ostream& operator<<(ostream& os, Record& record);

    /**
     * @brief Overloads the input stream operator for the Record class.
     * @param is Input stream reference.
     * @param record Reference to the Record instance.
     * @return Modified input stream reference.
     */
    friend istream& operator>>(istream& is, Record& record);
};

#endif // RECORD_H
