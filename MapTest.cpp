/**
 * @file main.cpp
 * @brief Test program for the Map class.
 * @author Özge Erarslan
 * @date December, 2024
 *
 * This program demonstrates the functionalities of the Map class, including:
 * - Creating a map
 * - Inserting points into the map
 * - Displaying the map using `showMap` and `<<` operator
 * - Changing the grid size of the map
 * - Clearing the map
 */

#include <iostream>
#include "Map.h"
#include <cstdlib>

using namespace std;

/**
 * @brief Main function to test the Map class.
 *
 * This function performs the following tasks:
 * - Creates a map with a specified size and grid resolution
 * - Inserts random points into the map
 * - Displays the map using different methods
 * - Modifies the grid size of the map
 * - Clears the map and verifies the results
 *
 * @return 0 on successful execution.
 */
int main() {
    // Create a Map object with a 10x10 grid and a grid size of 1.0
    Map map(10, 10, 1.0);
    map.printInfo();

    // Insert 10 random points into the map
    for (int i = 0; i < 10; i++) {
        double randX = rand() % 10; // Generate a random X-coordinate
        double randY = rand() % 10; // Generate a random Y-coordinate

        Point p(randX, randY);
        map.insertPoint(p);
        cout << "Inserted point (" << randX << ", " << randY << ")\n";
    }

    // Display the map using the `showMap` method
    cout << "\nMap after inserting 10 points (using showMap):\n";
    map.showMap();

    // Display the map using the `<<` operator
    cout << "\nMap after inserting 10 points (using << operator):\n";
    cout << map;

    // Change the grid size of the map
    double newGridSize = 2.0;
    cout << "\nChanging grid size to " << newGridSize << endl;
    map.setGridSize(newGridSize);

    // Print updated map information
    map.printInfo();

    // Insert a new point into the map
    Point p2(4.5, 4.5);
    map.insertPoint(p2);
    cout << "Inserted point (" << p2.getX() << ", " << p2.getY() << ")\n";

    // Display the map again with the updated grid size
    cout << "\nMap after changing grid size and inserting a new point:\n";
    cout << map;

    // Clear the map
    cout << "\nClearing the map...\n";
    map.clearMap();

    // Display the map after clearing
    cout << "\nMap after clearing:\n";
    map.showMap();

    return 0;
}
