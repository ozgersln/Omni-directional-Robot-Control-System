#include <iostream>
#include "Point.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

/**
 * @class Point
 * @author Özge Erarslan
 * @date December, 2024
 * @brief A class representing a 2D point with x and y coordinates.
 */
Point::Point(double _x, double _y) : x(_x), y(_y) { }

/**
 * @brief Get the x-coordinate of the point.
 * @return The x-coordinate as a double.
 */
double Point::getX() const { return x; }

/**
 * @brief Set the x-coordinate of the point.
 * @param xx The new x-coordinate value.
 */
void Point::setX(double xx) {
    x = xx;
}

/**
 * @brief Get the y-coordinate of the point.
 * @return The y-coordinate as a double.
 */
double Point::getY() const { return y; }

/**
 * @brief Set the y-coordinate of the point.
 * @param yy The new y-coordinate value.
 */
void Point::setY(double yy) {
    y = yy;
}

/**
 * @brief Get both x and y coordinates of the point.
 * @param[out] _x The x-coordinate to be returned.
 * @param[out] _y The y-coordinate to be returned.
 */
void Point::getPoint(double& _x, double& _y) {
    _x = x;
    _y = y;
}

/**
 * @brief Set both x and y coordinates of the point.
 * @param _x The new x-coordinate.
 * @param _y The new y-coordinate.
 */
void Point::setPoint(double _x, double _y) {
    x = _x;
    y = _y;
}

/**
 * @brief Calculate the distance from this point to another point.
 * @param pos Another point to calculate the distance to.
 * @return The Euclidean distance between the two points.
 */
double Point::findDistanceTo(Point pos) {
    double sum = (x - pos.x) * (x - pos.x) + (y - pos.y) * (y - pos.y);
    double distance = sqrt(sum);
    return distance;
}

/**
 * @brief Calculate the angle from this point to another point.
 * @param pos Another point to calculate the angle to.
 * @return The angle in degrees between the two points (0 to 360).
 */
double Point::findAngleTo(Point pos) {
    double dx = pos.getX() - this->x;
    double dy = pos.getY() - this->y;

    double angle = atan2(dy, dx);

    angle = angle * 180.0 / M_PI;
    if (angle < 0) {
        angle += 360.0;
    }
    return angle;
}

/**
 * @brief Overload the equality operator to compare two points.
 * @param other Another Point object to compare with.
 * @return True if the points are equal, false otherwise.
 */
bool Point::operator==(const Pose& other) {
    return (x == other.getX()) && (y == other.getY());
}
