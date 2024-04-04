#include <iostream>
#include "OpenTriangle.h"
#include "ClosedTriangle.h"
#include <string>


using namespace std;

int main()
{
	cout << "Open inheritance" << endl;
	OpenTriangle ABC;
	cin >> ABC;
	cout << ABC;

	cout << "AB(P1P2) = " << ABC.get_a() << endl;
	cout << "BC(P2P3) = " << ABC.get_b() << endl;
	cout << "AC(P1P3) = " << ABC.get_c() << endl;
	cout << endl;

	cout << "Type of ABC = " << ABC.triangleType() << endl;
	cout << "Perimeter ABC = " << ABC.perimeter() << endl;
	cout << "Square ABC = " << ABC.square() << endl;

	cout << "Closed inheritance" << endl;
	ClosedTriangle XYZ;
	cin >> XYZ;
	cout << XYZ;

	cout << "XY(P1P2) = " << XYZ.get_a() << endl;
	cout << "YZ(P2P3) = " << XYZ.get_b() << endl;
	cout << "XZ(P1P3) = " << XYZ.get_c() << endl;
	cout << endl;

	cout << "Type of XYZ = " << XYZ.triangleType() << endl;
	cout << "Perimeter XYZ = " << XYZ.perimeter() << endl;
	cout << "Square XYZ = " << XYZ.square() << endl;
}
