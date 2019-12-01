#include <iostream>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

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

int dayOfYear(Date date)
{
	int day = date.day;
	for (int i = 1; i < date.month; ++i)
		day += monthLength(date.year, i);
	return day;
}

int main(void)
{
	Date d;
	cout << "Enter year, month, day: ";
	cin >> d.year >> d.month >> d.day;
	cout << dayOfYear(d) << endl;
	return 0;
}