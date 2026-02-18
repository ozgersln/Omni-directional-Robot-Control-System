/**
 * @file Pose.h
 * @Author Mervenur Çakmakoðlu (152120221128@ogrenci.ogu.edu.tr)
 * @date December, 2024
 * @brief Represents the position and orientation of a robot.
 *
 * The Pose class stores the x, y coordinates and the orientation angle (theta) of a robot.
 * It provides methods for getting and setting these values, as well as utility functions
 * for pose arithmetic and distance/angle calculations.
 */

#ifndef POSE_H
#define POSE_H

#include <cmath>

 /**
  * @class Pose
  * @brief Stores the position and orientation of a robot.
  */
class Pose {
private:
    double x; //!< X-coordinate of the robot
    double y; //!< Y-coordinate of the robot
    double th; //!< Orientation angle (theta) of the robot

public:
    //! Default constructor
    Pose();

    //! Constructor with x, y, and th initialization
    Pose(double x, double y, double th);

    //! Gets the x-coordinate
    double getX() const;

    //! Gets the y-coordinate
    double getY() const;

    //! Gets the orientation angle (theta)
    double getTh() const;

    //! Sets the x-coordinate
    void setX(double x);

    //! Sets the y-coordinate
    void setY(double y);

    //! Sets the orientation angle (theta)
    void setTh(double th);

    //! Checks if two poses are equal
    bool operator==(const Pose& other) const;

    //! Adds two poses
    Pose operator+(const Pose& other) const;

    //! Subtracts one pose from another
    Pose operator-(const Pose& other) const;

    //! Adds another pose to the current pose
    Pose& operator+=(const Pose& other);

    //! Subtracts another pose from the current pose
    Pose& operator-=(const Pose& other);

    //! Compares two poses based on x, y, and th
    bool operator<(const Pose& other) const;

    //! Gets the pose as x, y, and th
    void getPose(double& _x, double& _y, double& _th) const;

    //! Sets the pose using x, y, and th
    void setPose(double _x, double _y, double _th);

    //! Calculates the distance to another pose
    double findDistanceTo(const Pose& other) const;

    //! Calculates the angle to another pose
    double findAngleTo(const Pose& other) const;
};

#endif // POSE_H

