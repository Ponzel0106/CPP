#include <iostream>
#include <string>

using namespace std;

class Square
{
public:
		Square(double side);
		void setSide(double s);
		void print();
private:
		double side;
		double area;
};

Square::Square(double side)
{
		this->side = side;
		this->area = side * side;
}

void Square::setSide(double s)
{
		if (s < 0.)
			return;
		side = s;
		area = s * s;
}

void Square::print()
{
		cout << "Square: side=" << side << " area=" << area << endl;
}

int main()
{
		Square s(4.);
		s.print();

		s.setSide(2.);
		s.print();

		s.setSide(-33.);
		s.print();

		return 0;
}