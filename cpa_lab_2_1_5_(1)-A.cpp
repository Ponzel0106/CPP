#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void)
{
	int year;
	bool leap;

	cout << "Enter a year: ";
	cin >> year;

	if (year < 1582)
		cout << "Warning: using Gregorian scheme to"
				"determine leapness of non-Gregorian year!" << endl;
	if (year % 400 == 0)
		leap = true;
	else if (year % 100 == 0)
		leap = false;
	else if (year % 4 == 0)
		leap = true;
	else
		leap = false;

	cout << (leap ? "Leap year" : "Common year") << endl;

	return 0;
}