#include "Point.h"
#include <iostream>
#include <string>
class OpenTriangle :
    public Point
{
private:
    Point P2, P3;
public:
    Point getP2() { return P2; }
    Point getP3() { return P3; }
    void setP1(double x, double y) { setX(x); setY(y); }
    void setP2(double x, double y) { P2.setX(x); P2.setY(y); }
    void setP3(double x, double y) { P3.setX(x); P3.setY(y); }

    OpenTriangle();
    OpenTriangle(double x1, double y1, double x2, double y2, double x3, double y3);

    operator string() const;

    double getObjX(Point obj) const { return obj.getX(); }
    double getObjY(Point obj) const { return obj.getY(); }
    void setObjX(Point obj, double value) { obj.setX(value); }
    void setObjY(Point obj, double value) { obj.setY(value); }

    double get_a()const { return distanceOfPoints(*this, P2); };
    double get_b() const { return distanceOfPoints(P2, P3); };
    double get_c() const { return distanceOfPoints(*this, P3); };

    double get_A() const;
    double get_B()const;
    double get_C()const;

    double hA() const;
    double hB() const;
    double hC()const;

    friend istream& operator >> (istream& in, OpenTriangle& obj);
    friend ostream& operator << (ostream& in, const OpenTriangle& obj);


    double perimeter()const;
    string triangleType()const;
    double square() const;
};

