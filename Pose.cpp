/**
 * @file Pose.cpp
 * @Author Mervenur Çakmakoðlu (152120221128@ogrenci.ogu.edu.tr)
 * @date December, 2024
 * @brief Implementation of the Pose class for handling robot pose information.
 */

#include "Pose.h"
#include <cmath>

 // Tanýmlý deðilse M_PI sabiti tanýmlanýr
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/**
 * @brief Default constructor that initializes the pose to (0, 0, 0).
 */
Pose::Pose() : x(0.0), y(0.0), th(0.0) {}

/**
 * @brief Constructor that initializes the pose with given values for x, y, and theta.
 * @param x X coordinate of the pose.
 * @param y Y coordinate of the pose.
 * @param th Orientation (theta) of the pose in radians.
 */
Pose::Pose(double x, double y, double th) : x(x), y(y), th(th) {}

/**
 * @brief Gets the X coordinate of the pose.
 * @return The X coordinate of the pose.
 */
double Pose::getX() const { return x; }

/**
 * @brief Gets the Y coordinate of the pose.
 * @return The Y coordinate of the pose.
 */
double Pose::getY() const { return y; }

/**
 * @brief Gets the orientation (theta) of the pose.
 * @return The orientation (theta) of the pose in radians.
 */
double Pose::getTh() const { return th; }

/**
 * @brief Sets the X coordinate of the pose.
 * @param x The new X coordinate value.
 */
void Pose::setX(double x) { this->x = x; }

/**
 * @brief Sets the Y coordinate of the pose.
 * @param y The new Y coordinate value.
 */
void Pose::setY(double y) { this->y = y; }

/**
 * @brief Sets the orientation (theta) of the pose.
 * @param th The new orientation value in radians.
 */
void Pose::setTh(double th) { this->th = th; }

/**
 * @brief Equality operator to compare two poses.
 * @param other The other pose to compare with.
 * @return True if both poses have the same coordinates and orientation, otherwise false.
 */
bool Pose::operator==(const Pose& other) const {
    return (x == other.x && y == other.y && th == other.th);
}

/**
 * @brief Adds two poses together by adding their respective coordinates and orientations.
 * @param other The pose to add.
 * @return The resulting pose after addition.
 */
Pose Pose::operator+(const Pose& other) const {
    return Pose(x + other.x, y + other.y, th + other.th);
}

/**
 * @brief Subtracts the given pose from the current pose by subtracting their respective coordinates and orientations.
 * @param other The pose to subtract.
 * @return The resulting pose after subtraction.
 */
Pose Pose::operator-(const Pose& other) const {
    return Pose(x - other.x, y - other.y, th - other.th);
}

/**
 * @brief Adds the given pose to the current pose (modifies current pose).
 * @param other The pose to add.
 * @return A reference to the updated pose.
 */
Pose& Pose::operator+=(const Pose& other) {
    this->x += other.x;
    this->y += other.y;
    this->th += other.th;
    return *this;
}

/**
 * @brief Subtracts the given pose from the current pose (modifies current pose).
 * @param other The pose to subtract.
 * @return A reference to the updated pose.
 */
Pose& Pose::operator-=(const Pose& other) {
    this->x -= other.x;
    this->y -= other.y;
    this->th -= other.th;
    return *this;
}

/**
 * @brief Compares two poses based on their X and Y coordinates.
 * @param other The other pose to compare with.
 * @return True if the current pose's X and Y are less than the other's, otherwise false.
 */
bool Pose::operator<(const Pose& other) const {
    return (x < other.x && y < other.y);
}

/**
 * @brief Gets the pose values (X, Y, Theta).
 * @param _x Reference to store the X coordinate.
 * @param _y Reference to store the Y coordinate.
 * @param _th Reference to store the orientation (theta).
 */
void Pose::getPose(double& _x, double& _y, double& _th) const {
    _x = x;
    _y = y;
    _th = th;
}

/**
 * @brief Sets the pose values (X, Y, Theta).
 * @param _x The new X coordinate value.
 * @param _y The new Y coordinate value.
 * @param _th The new orientation (theta) value in radians.
 */
void Pose::setPose(double _x, double _y, double _th) {
    this->x = _x;
    this->y = _y;
    this->th = _th;
}

/**
 * @brief Calculates the distance to another pose.
 * @param other The other pose to calculate the distance to.
 * @return The Euclidean distance between the current pose and the other pose.
 */
double Pose::findDistanceTo(const Pose& other) const {
    double dx = other.x - x;
    double dy = other.y - y;
    return std::sqrt(dx * dx + dy * dy);
}

/**
 * @brief Calculates the angle to another pose.
 * @param other The other pose to calculate the angle to.
 * @return The angle in degrees between the current pose and the other pose.
 */
double Pose::findAngleTo(const Pose& other) const {
    double dx = other.x - x;
    double dy = other.y - y;
    double angle = std::atan2(dy, dx) * 180.0 / M_PI;

    if (angle < 0) {
        angle += 360.0;
    }
    return angle;
}