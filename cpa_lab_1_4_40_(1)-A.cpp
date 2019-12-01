#include <iostream>

using namespace std;

int main(void)
{
	float  pi = 3.14159265359;
	float  x, xx, pipi, xdivpi_sq, y;

	cout << "Enter value for x: ";
	cin >> x;

	xx = x * x;
	pipi = pi * pi;
	xdivpi_sq = xx / pipi;
	y =  xdivpi_sq / (xx + 0.5f) * (1.0f + xdivpi_sq / ((xx - 0.5) * (xx - 0.5)));

	cout << "y = " << y << endl;
	return 0;
}