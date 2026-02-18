/**
 * @file RecordTest.cpp
 * @brief Unit tests for the Record class.
 *
 * This file contains test cases to validate the functionality of the Record class,
 * including file operations, line reading/writing, and stream operator overloading.
 *
 * @author R�meysa �elik
 * @date December, 2024
 */

#include "Record.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <fstream>

using namespace std;

/**
 * @brief Main function to execute all unit tests for the Record class.
 *
 * This function performs the following tests:
 * - Setting a file name.
 * - Opening and closing files.
 * - Writing and reading lines from a file.
 * - Using overloaded << and >> operators.
 * - Cleaning up test files.
 *
 * @return int Returns 0 on successful execution.
 */
int main() {
    Record record;
    string testFileName = "test_file.txt";
    record.setFileName(testFileName);

    // Test opening the file
    bool isFileOpened = record.openFile();
    assert(isFileOpened == true);

    // Test writing lines to the file
    bool writeSuccess1 = record.writeLine("First line");
    bool writeSuccess2 = record.writeLine("Second line");
    assert(writeSuccess1 == true);
    assert(writeSuccess2 == true);

    record.closeFile();

    // Test reopening the file
    bool reOpenSuccess = record.openFile();
    assert(reOpenSuccess == true);

    // Test reading lines from the file
    string firstLine = record.readLine();
    string secondLine = record.readLine();
    assert(firstLine == "First line");
    assert(secondLine == "Second line");

    // Test << operator
    cout << "Testing << operator:\n";
    cout << record;

    Record anotherRecord;
    anotherRecord.setFileName("another_test_file.txt");

    // Test opening another file
    bool anotherFileOpened = anotherRecord.openFile();
    assert(anotherFileOpened == true);

    // Test reading from a string input stream into the file
    istringstream input("Third line\nFourth line\n");
    input >> anotherRecord;
    anotherRecord.closeFile();
    anotherRecord.openFile();

    string thirdLine = anotherRecord.readLine();
    string fourthLine = anotherRecord.readLine();

    assert(thirdLine == "Third line");
    assert(fourthLine == "Fourth line");

    // Test closing files
    bool closeSuccess1 = record.closeFile();
    bool closeSuccess2 = anotherRecord.closeFile();
    assert(closeSuccess1 == true);
    assert(closeSuccess2 == true);

    // Clean up test files
    remove(testFileName.c_str());
    remove("another_test_file.txt");

    cout << "All test cases passed!" << endl;
    return 0;
}
