#ifndef source_h
#define source_h


class Point {

private:
	double x, y;
public:
	Point();
	Point(double xv, double yv);
	Point(Point& pt);
	double getx();
	double gety();
};

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(double xv, double yv)
{
	x = xv;
	y = yv;
}

Point::Point(Point & pt)
{
	x = pt.x;
	y = pt.y;
}

double Point::getx()
{
	return x;
}

double Point::gety()
{
	return y;
}

class Rectangle : public Point
{
public:
	Rectangle(double xv = 0, double yv = 0, double l = 0, double w = 0);
	Rectangle(Rectangle&);
	~Rectangle();
	int position(Point & pt);
private:
	double length, width;
};

Rectangle::Rectangle(double xv, double yv, double l, double w) : Point(xv, yv)
{
	length = l;
	width = w;
}

inline Rectangle::Rectangle(Rectangle & p) : Point(p.getx(), p.gety())
{
	length = p.length;
	width = p.width;
}

Rectangle::~Rectangle()
{
}

inline int Rectangle::position(Point & pt)
{
	if (getx() < pt.getx() && getx() + length > pt.getx() && gety() < pt.gety() && gety() + width > pt.gety()) return -1;
	else if (getx() > pt.getx() || getx() + length < pt.getx() || gety() > pt.gety() || gety() + width < pt.gety()) return 1;
	else return 0;
}

class Circle : public Point
{
public:
	Circle(double xv = 0, double yv = 0, double r1 = 0);
	Circle(Circle & p);
	~Circle();
	int position(Point &pt);
private:
	double radius;
};

Circle::Circle(double xv, double yv, double r1) : Point(xv,yv)
{
	radius = r1;
}

inline Circle::Circle(Circle & p) : Point(p.getx(), p.gety())
{
	radius = p.radius;
}

Circle::~Circle()
{
}
inline int Circle::position(Point & pt)
{
	if (((pt.getx() - getx()) * (pt.getx() - getx()) + (pt.gety() - gety()) * (pt.gety() - gety()) > radius * radius)) return 1;
	else if (((pt.getx() - getx()) * (pt.getx() - getx()) + (pt.gety() - gety()) * (pt.gety() - gety()) < radius * radius)) return -1;
	else return 0;
}
#endif // !source_h