#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Point2D
{
public:
	Point2D(double x = 0, double y = 0);
	string toString() const;
	double distanceTo(Point2D that);
	// Getters
	double getX() const noexcept;
	double getY() const noexcept;
private:
	double x;
	double y;
};

Point2D::Point2D(double x, double y)
	: x(x), y(y)
{}

string Point2D::toString() const
{
	return to_string(x) + ", " + to_string(y);
}

double Point2D::distanceTo(Point2D that)
{
	return sqrt((x - that.x) * (x - that.x) + (y - that.y) * (y - that.y));
}

double Point2D::getX() const noexcept
{
	return x;
}

double Point2D::getY() const noexcept
{
	return y;
}

class Line2D
{
public:
	Line2D(double slope, double y_intercept);
	Line2D(Point2D pointA, Point2D pointB);
	string toString() const;
private:
	double slope;
	double y_intercept;
};

Line2D::Line2D(double slope, double y_intercept)
	: slope(slope), y_intercept(y_intercept)
{}

Line2D::Line2D(Point2D pointA, Point2D pointB)
{
	const double
		xDiff = pointB.getX() - pointA.getX(),
		yDiff = pointB.getY() - pointA.getY();
	if (xDiff == 0)
		; // !
	slope = yDiff / xDiff;
	y_intercept = pointA.getY() - slope * pointA.getX();
}

string Line2D::toString() const
{
	if (y_intercept > 0)
		return "y = " + std::to_string(slope) + "x + " + std::to_string(y_intercept);
	if (y_intercept < 0)
		return "y = " + std::to_string(slope) + "x - " + std::to_string(-y_intercept);
	return "y = " + std::to_string(slope) + "x";
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
	Line2D line(pts[0], pts[1]);
	cout << line.toString() << endl;
	return 0;
}