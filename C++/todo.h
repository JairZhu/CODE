#include <cmath>
#include <iostream>
using namespace std;
#define PI acos(-1.0)

class point
{
public:
	point(double x1 = 0, double y1 = 0) : x(x1), y(y1)
	{
	}
	~point() {}
	virtual void print() { 
		cout << fixed;
		cout.precision(2);
		cout << "point : " << x << ' ' << y << endl;
	}
	double getx() { return x; }
	double gety() { return y; }
private:
	double x, y;
};

class vector1 : virtual point
{
public:
	vector1(double x1 = 0, double y1 = 0, double dx1 = 0, double dy1 = 0) : point(x1, y1)
	{
		dx = dx1;
		dy = dy1;
		length = sqrt(dx1 * dx1 + dy1 * dy1);
	}
	~vector1() {}
	double getlength() { return length; }
	virtual void print() { 
		cout << fixed;
		cout.precision(2);
		cout << "length : " << length << endl;
		point::print();
	}
private:
	double dx, dy;
	double length;
};

class circle: virtual public point 
{
public:
	circle(double x1 = 0, double y1 = 0, double r1 = 0) : point(x1, y1), r(r1)
	{
		area = PI * r1 * r1;
	}
	~circle() {}
	double getarea() { return area; }
	virtual void print() {
		cout << fixed;
		cout.precision(2);
		cout << "area : " << area << endl;
		point::print();
	}
private:
	double r;
	double area;
};

class todo : public vector1, public circle
{
public:
	todo(double x1 = 0, double y1 = 0, double dx1 = 0, double dy1 = 0, double r1 = 0) :point(x1, y1), vector1(x1, y1, dx1, dy1), circle(x1, y1, r1)
	{
		volume = 2 * r1 * getlength() + getarea();
	}
	~todo() {}
	void print() {
		cout << fixed;
		cout.precision(2);
		cout << "volume : " << volume << endl
			<< "length : " << getlength() << endl;
		point::print();
		cout << "area : " << getarea() << endl;
		point::print();
	}
private:
	double volume;
};