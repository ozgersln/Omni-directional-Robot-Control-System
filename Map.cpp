#include <iostream>
#include "Map.h"

/**

 * @class Map
 * @brief A class that represents a 2D grid map for spatial representation.
 * @author Özge Erarslan
 * @date December, 2024
 */



 /**
  * @brief Constructs a Map object with specified grid dimensions and grid size.
  * @param x Number of grids in the X direction (default is 0).
  * @param y Number of grids in the Y direction (default is 0).
  * @param size The size of each grid (default is 1.0).
  */
Map::Map(int x, int y, double size) : numberX(x), numberY(y), gridSize(size) {
    grid = new int* [numberX];
    for (int i = 0; i < numberX; i++) {
        grid[i] = new int[numberY];
        for (int j = 0; j < numberY; j++) {
            grid[i][j] = 0;
        }
    }
}

/**
 * @brief Destroys the Map object and deallocates the memory used by the grid.
 */
Map::~Map() {
    for (int i = 0; i < numberX; i++) {
        delete[] grid[i];  // Free each row
    }
    delete[] grid;  // Free the grid array
}

/**
 * @brief Inserts a point into the map by marking its corresponding grid cell.
 * @param p A Point object to insert.
 */
void Map::insertPoint(Point p) {
    int gridX = static_cast<int>(p.getX() / gridSize);
    int gridY = static_cast<int>(p.getY() / gridSize);

    if (gridX >= 0 && gridX < numberX && gridY >= 0 && gridY < numberY) {
        grid[gridX][gridY] = 1;
    }
    else {
        std::cout << "Error: Point is out of bounds!" << std::endl;
    }
}

/**
 * @brief Retrieves the value of a specific grid cell.
 * @param indexX The X index of the grid cell.
 * @param indexY The Y index of the grid cell.
 * @return The value at the specified grid cell.
 */
int Map::getGrid(int indexX, int indexY) {
    return grid[indexX][indexY];
}

/**
 * @brief Sets the value of a specific grid cell.
 * @param indexX The X index of the grid cell.
 * @param indexY The Y index of the grid cell.
 * @param value The value to set for the grid cell.
 */
void Map::setGrid(int indexX, int indexY, int value) {
    grid[indexX][indexY] = value;
}

/**
 * @brief Clears the entire map by resetting all grid cells to 0.
 */
void Map::clearMap() {
    for (int i = 0; i < numberX; i++) {
        for (int j = 0; j < numberY; j++) {
            grid[i][j] = 0;
        }
    }
}

/**
 * @brief Prints basic information about the map.
 */
void Map::printInfo() const {
    std::cout << "Map information: " << std::endl;
    std::cout << "Number of grids in X direction: " << numberX << std::endl;
    std::cout << "Number of grids in Y direction: " << numberY << std::endl;
    std::cout << "Grid size (in meters or units): " << gridSize << std::endl;
}

/**
 * @brief Displays the map in the console, showing '.' for empty cells and 'x' for occupied cells.
 */
void Map::showMap() {
    for (int i = 0; i < numberX; i++) {
        for (int j = 0; j < numberY; j++) {
            if (grid[i][j] == 0) {
                std::cout << ".  ";
            }
            else if (grid[i][j] == 1) {
                std::cout << "x  ";
            }
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Gets the number of grids in the X direction.
 * @return The number of grids in the X direction.
 */
int Map::getNumberX() const {
    return numberX;
}

/**
 * @brief Gets the number of grids in the Y direction.
 * @return The number of grids in the Y direction.
 */
int Map::getNumberY() const {
    return numberY;
}

/**
 * @brief Calculates the total number of grids in the map.
 * @return The total number of grids.
 */
double Map::addGridSize() {
    return numberX * numberY;
}

/**
 * @brief Sets the size of each grid.
 * @param size The new grid size.
 */
void Map::setGridSize(double size) {
    gridSize = size;
}

/**
 * @brief Overloaded stream insertion operator for displaying the map.
 * @param os The output stream object.
 * @param map The Map object to display.
 * @return The output stream with the map data appended.
 */
std::ostream& operator<<(std::ostream& os, const Map& map) {
    for (int i = 0; i < map.getNumberX(); i++) {
        for (int j = 0; j < map.getNumberY(); j++) {
            if (map.grid[i][j] == 0) {
                os << ".  ";
            }
            else if (map.grid[i][j] == 1) {
                os << "x  ";
            }
        }
        os << std::endl;
    }
    return os;
}
