#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Point2D
{
public:
	Point2D(double x = 0, double y = 0);
	string toString();
	double distanceTo(Point2D that);
private:
	double x;
	double y;
};

Point2D::Point2D(double x, double y)
	: x(x), y(y)
{}

string Point2D::toString()
{
	return to_string(x) + ", " + to_string(y);
}

double Point2D::distanceTo(Point2D that)
{
	return sqrt((x - that.x) * (x - that.x) + (y - that.y) * (y - that.y));
}

int main()
{
	Point2D pts[2];
	double x, y;
	for (int i = 0; i < 2; ++i)
	{
		cin >> x >> y;
		pts[i] = Point2D(x, y);
	}
	cout << pts[0].distanceTo(pts[1]) << endl;
	return 0;
}