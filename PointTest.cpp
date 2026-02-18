/**
 * @file main.cpp
 * @brief Test program for Point and Pose classes.
 * @author Özge Erarslan
 * @date December, 2024
 *
 * This program demonstrates the functionalities of the Point and Pose classes,
 * including distance and angle calculations, equality operator testing,
 * and coordinate manipulation.
 */

#include <iostream>
#include "Point.h"
#include "Pose.h"

using namespace std;

/**
 * @brief Main function to test the Point and Pose classes.
 *
 * This function tests:
 * - Creating and printing points
 * - Calculating distance and angle between points
 * - Using the equality operator
 * - Modifying point coordinates
 *
 * @return 0 on successful execution.
 */
int main() {
    // Create two Point objects
    Point p1(3.0, 4.0);
    Point p2(6.0, 8.0);

    cout << "Initial Points:" << endl;

    // Print the coordinates of p1
    double x1, y1;
    p1.getPoint(x1, y1);
    cout << "p1: (" << x1 << ", " << y1 << ")" << endl;

    // Print the coordinates of p2
    double x2, y2;
    p2.getPoint(x2, y2);
    cout << "p2: (" << x2 << ", " << y2 << ")" << endl;

    // Calculate and print the distance between p1 and p2
    double distance = p1.findDistanceTo(p2);
    cout << "\nDistance between p1 and p2: " << distance << endl;

    // Calculate and print the angle from p1 to p2
    double angle = p1.findAngleTo(p2);
    cout << "Angle from p1 to p2: " << angle << " degrees" << endl;

    // Test the equality operator (==) with a Pose object
    Pose p3(7.0, 4.0, 0.0);

    cout << "\np3 Information:" << endl;
    cout << "x: " << p3.getX() << ", y: " << p3.getY() << ", th: " << p3.getTh() << endl;
    cout << "\np1 and p3 are " << (p1 == p3 ? "equal." : "not equal.") << endl;

    // Change the coordinates of p1 and print the updated values
    p1.setPoint(0.0, 0.0);
    p1.getPoint(x1, y1);
    cout << "\nAfter changing p1 to (0.0, 0.0):" << endl;
    cout << "p1: (" << x1 << ", " << y1 << ")" << endl;

    // Modify the x and y coordinates of p1 individually
    p1.setX(1.5);
    p1.setY(2.5);
    p1.getPoint(x1, y1);
    cout << "After changing p1 to (1.5, 2.5):" << endl;
    cout << "p1: (" << x1 << ", " << y1 << ")" << endl;

    return 0;
}
