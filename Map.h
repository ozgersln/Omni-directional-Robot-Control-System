/*
* @author Özge Erarslan
* @date December, 2024
*/


#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "Point.h"
using namespace std;

class Map {
    int** grid;
    int numberX;
    int numberY;
    double  gridSize;
public:
    Map(int x, int y, double size);
    void insertPoint(Point);
    int getGrid(int indexX, int indexY);
    void  setGrid(int indexX, int indexY, int value);
    void clearMap();
    void printInfo() const;
    friend ostream& operator<<(std::ostream& os, const Map& map);
    void showMap();
    int getNumberX() const;
    int getNumberY()const;
    double addGridSize();
    void setGridSize(double size);
    ~Map();
};

#endif