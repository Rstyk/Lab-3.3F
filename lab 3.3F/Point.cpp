#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(double a, double b)
{
	x = a;
	y = b;
}

Point::Point(const Point& obj)
{
	*this = obj;
}

Point& Point::operator=(const Point& obj)
{
	x = obj.x;
	y = obj.y;
	return *this;
}

Point::operator string() const
{
	stringstream sout;
	sout << "x = " << x << endl << " y = " << y << endl;
	return sout.str();
}




double Point::distanceToOrigin()
{
	double result = sqrt(x * x + y * y);
	return result;
}
void Point::polarizeCoords()
{
	double dist = distanceToOrigin();
	double angle = acos(1.0 * x / dist);
	*this = Point(dist, angle);
}
Point& Point::operator++()
{
	x++;
	return *this;
}

Point& Point::operator--()
{
	x--;
	return *this;
}

Point Point::operator++(int)
{
	Point obj(*this);
	y++;
	return *this;
}

Point Point::operator--(int)
{
	Point obj(*this);
	y--;
	return *this;
}

istream& operator>>(istream& in, Point& obj)
{
	cout << " x = "; in >> obj.x;
	cout << " y = "; in >> obj.y;
	cout << endl;
	return in;
}
ostream& operator << (ostream& out, const Point& obj)
{
	out << string(obj);
	return out;
}
double distanceOfPoints(Point p1, Point p2)
{
	double x1 = p1.getX();
	double y1 = p1.getY();
	double x2 = p2.getX();
	double y2 = p2.getY();

	double dx = x1 - x2;
	double dy = y1 - y2;
	double result = sqrt(dx * dx + dy * dy);
	return result;
}

bool operator==(Point p1, Point p2)
{
	return (p1.getX() == p2.getX() && p1.getY() == p2.getY());
}

bool operator!=(Point p1, Point p2)
{
	return !(p1 == p2);
}

