#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Point
{
private:
	double x, y;
public:
	double getX() { return x; }
	double getY() { return y; }
	void setX(double value) { x = value; }
	void setY(double value) { y = value; }

	Point();
	Point(double a, double b);
	Point(const Point& obj);

	Point& operator = (const Point& obj);
	operator string() const;

	double distanceToOrigin();
	void moveX(double value) { x += value; }
	void moveY(double value) { y += value; }
	void polarizeCoords();


	friend istream& operator >> (istream& in, Point& obj);
	friend ostream& operator << (ostream& in, const Point& obj);
	Point& operator ++();
	Point& operator --();
	Point operator ++(int);
	Point operator --(int);

	friend double distanceOfPoints(Point p1, Point p2);
	friend bool operator ==(Point p1, Point p2);
	friend bool operator != (Point p1, Point p2);

	Point getPoint() { return *this; }
	void setPoint(Point& obj) { *this = obj; }
};
