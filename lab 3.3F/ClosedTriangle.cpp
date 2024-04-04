#include "ClosedTriangle.h"

ClosedTriangle::ClosedTriangle()
{
	Point(0, 0);
	P2 = Point(0, 0);
	P3 = Point(0, 0);
}

ClosedTriangle::ClosedTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	Point(x1, y1);
	P2 = Point(x2, y2);
	P3 = Point(x3, y3);
}

ClosedTriangle::operator string() const
{
	ClosedTriangle C = *this;
	return  "First point P1 \n" + string(C.getPoint()) + "\n" +
		"Second point P2" + "\n" + string(P2) + "\n"
		+ "Third point P3" + "\n" + string(P3) + "\n";
}

double ClosedTriangle::get_A()const
{
	double angle;
	double a, b, c;
	double cosA;

	a = get_a();
	b = get_b();
	c = get_c();

	double n = a * a + c * c - b * b;
	double m = 2 * a * c;

	cosA = (1.0 * n) / (1.0 * m);
	angle = acos(cosA);

	return angle;
}

double ClosedTriangle::get_B()  const
{
	double angle;
	double a, b, c;
	double cosA;

	a = get_a();
	b = get_b();
	c = get_c();

	double n = a * a + b * b - c * c;
	double m = 2 * a * b;

	cosA = (1.0 * n) / (1.0 * m);
	angle = acos(cosA);

	return angle;
}

double ClosedTriangle::get_C() const
{
	double angle;
	double a, b, c;
	double cosA;

	a = get_a();
	b = get_b();
	c = get_c();

	double n = b * b + c * c - a * a;
	double m = 2 * b * c;

	cosA = (1.0 * n) / (1.0 * m);
	angle = acos(cosA);

	return angle;
}

double ClosedTriangle::hA() const
{
	double BC = get_b();
	double S = square();

	double result = 2.0 * S / BC;
	return result;
}
double ClosedTriangle::hB() const
{
	double AC = get_c();
	double S = square();

	double result = 2.0 * S / AC;
	return result;
}
double ClosedTriangle::hC() const
{
	double AB = get_a();
	double S = square();

	double result = 2.0 * S / AB;
	return result;
}

double ClosedTriangle::perimeter()const
{
	double res;
	res = get_a() + get_b() + get_c();
	return res;
}

string ClosedTriangle::triangleType()  const {
	string result;
	double a, b, c;
	a = get_a();
	b = get_b();
	c = get_c();

	double angle_a, angle_b, angle_c;
	angle_a = get_A();
	angle_b = get_B();
	angle_c = get_C();

	if (a == b && b == c)
		result = "Equilateral triangle";
	else if (a == b || a == c || b == c) {
		if (sin(angle_a) == 1.0 || sin(angle_b) == 1.0 || sin(angle_c) == 1.0)
			result = "Right-angled isosceles triangle";
		else
			result = "Isosceles triangle";
	}
	else if (sin(angle_a) == 1.0 || sin(angle_b) == 1.0 || sin(angle_c) == 1.0)
		result = "Right-angled triangle";
	else
		result = "Scalene triangle ";

	return result;
}

double ClosedTriangle::square() const
{
	double halfPerimeter = 1.0 * perimeter() / 2.0;
	double a, b, c;
	a = get_a();
	b = get_b();
	c = get_c();

	double result;
	result = sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c));

	return result;

}

istream& operator>>(istream& in, ClosedTriangle& obj)
{
	Point P1;
	cout << "First point P1" << endl;
	in >> P1;
	cout << "Second point P2" << endl;
	in >> obj.P2;
	cout << "Third point P3" << endl;
	in >> obj.P3;
	cout << endl;
	obj.setPoint(P1);
	return in;
}

ostream& operator<<(ostream& out, const ClosedTriangle& obj)
{

	out << string(obj);
	return out;
}

