/*
* @author Özge Erarslan
* @date December, 2024
*/


#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "Pose.h"

class Point {
	double x;
	double y;
public:
	Point(double _x, double _y);
	double getX() const;
	void setX(double);
	double getY() const;
	void setY(double);
	bool operator==(const Pose& other);
	void getPoint(double &_x, double &_y);
	void setPoint(double _x, double _y);
	double findDistanceTo(Point pos);
	double findAngleTo(Point pos);
};

#endif