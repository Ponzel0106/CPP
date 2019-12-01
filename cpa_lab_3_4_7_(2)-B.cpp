#include <iostream>

using namespace std;

bool isLeap(int year)
{
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return true;
	return false;
}

int monthLength(int year, int month)
{
	constexpr int commonMonthLength[13] = {
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	return commonMonthLength[month] + (isLeap(year) && month == 2);
}

int main(void)
{
	for (int yr = 2000; yr < 2002; ++yr)
	{
		for (int mo = 1; mo <= 12; ++mo)
			cout << monthLength(yr, mo) << " ";
		cout << endl;
	}
	return 0;
}