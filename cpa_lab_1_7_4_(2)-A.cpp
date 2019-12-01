#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
constexpr float EPSILON = 1e-6;

int main(void)
{
	int a, b;
	cin >> a >> b;
	float x = 1. / a, y = 1. / b;
	if (std::abs(x - y) < EPSILON)
		 cout << "Results are equal (by " << EPSILON << " epsilon)" << endl;
	else
		 cout << "Results are not equal (by " << EPSILON << " epsilon)" << endl;
	return 0;
}