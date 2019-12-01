#include <iostream>
#include <string>

using namespace std;

class AdHocSquare
{
public:
	AdHocSquare(double side);
	void set_side(double side);
	double get_area();
	void print();
private:
	double side;
};


class LazySquare
{
public:
	LazySquare(double side);
	void set_side(double side);
	double get_area();
	void print();
private:
	double    side;
	double    area;
	bool      side_changed;
};

int main()
{
	cout << "AdHocSquare: " << endl;

	AdHocSquare s(4.);
	s.print();

	s.set_side(2.);
	s.print();

	s.set_side(-33.);
	s.print();

	cout << "LazySquare: " << endl;

	LazySquare s2(4.);
	s2.print();

	s2.set_side(2.);
	s2.print();

	s2.set_side(-33.);
	s2.print();

	return 0;
}

AdHocSquare::AdHocSquare(double s)
{
	side = s;
}

void AdHocSquare::set_side(double s)
{
	if (s < 0.)
		return;
	side = s;
}

double AdHocSquare::get_area()
{
	return side * side;
}

void AdHocSquare::print()
{
	cout << "Square: side=" << side << " area=" << get_area() << endl;
}

LazySquare::LazySquare(double s)
{
	side = s;
	area = s * s;
	side_changed = false;
}

void LazySquare::set_side(double s)
{
	if (s < 0. || side == s)
		return;
	side = s, side_changed = true;
}

double LazySquare::get_area()
{
	if (side_changed)
		area = side * side, side_changed = false;
	return area;
}

void LazySquare::print()
{
	cout << "Square: side=" << side << " area=" << get_area() << endl;
}