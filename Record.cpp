/**
 * @file Record.cpp
 * @author R�meysa �elik (152120211125@ogrenci.ogu.edu.tr)
 * @date December, 2024
 * @brief Implementation of the Record class for file operations.
 */

#include "Record.h"
#include <iostream>
using namespace std;

/**
 * @brief Opens the file in read, write, and append mode.
 * @return True if the file is successfully opened, false otherwise.
 */
bool Record::openFile() {
    if (fileName.empty()) {
        cerr << "File name not specified!" << std::endl;
        return false;
    }

    file.open(fileName, std::ios::in | std::ios::out | std::ios::app);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << fileName << std::endl;
        return false;
    }

    return true;
}

/**
 * @brief Closes the file if it is currently open.
 * @return True if the file is successfully closed, false otherwise.
 */
bool Record::closeFile() {
    if (file.is_open()) {
        file.close();
        if (file.fail()) {
            cerr << "Error: Failed to close the file: " << fileName << std::endl;
            return false;
        }
        return true;
    }
    cerr << "Warning: Attempted to close a file that is not open." << std::endl;
    return false;
}

/**
 * @brief Sets the file name for the record object.
 * @param name The name of the file to be set.
 */
void Record::setFileName(const string& name) {
    if (!name.empty()) {
        fileName = name;
    }
    else {
        cerr << "Error: The file name cannot be empty." << endl;
    }
}

/**
 * @brief Reads a line from the file.
 * @return The read line as a string. Returns an empty string on error or end of file.
 */
string Record::readLine() {
    string line;
    if (!file.is_open()) {
        cerr << "Error: File is not open." << endl;
        return "";
    }

    if (getline(file, line)) {
        return line;
    }
    else {
        cerr << "Error: Failed to read line or end of file reached." << endl;
        return "";
    }
}

/**
 * @brief Writes a string to the file.
 * @param str The string to write.
 * @return True if the string is successfully written, false otherwise.
 */
bool Record::writeLine(const string& str) {
    if (!file.is_open()) {
        file.open(fileName, ios::app);
        if (!file.is_open()) {
            return false;
        }
    }

    file << str << endl;
    return true;
}

/**
 * @brief Outputs all lines of the record to the stream.
 * @param os The output stream.
 * @param record The record object.
 * @return The output stream.
 */
ostream& operator<<(ostream& os, Record& record) {
    string line;
    while (!(line = record.readLine()).empty()) {
        os << line << endl;
    }
    return os;
}

/**
 * @brief Reads lines from the input stream and writes them to the record.
 * @param is The input stream.
 * @param record The record object.
 * @return The input stream.
 */
istream& operator>>(istream& is, Record& record) {
    string line;
    while (getline(is, line)) {
        record.writeLine(line);
    }
    return is;
}
