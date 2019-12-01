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

int daysBetween(Date d1, Date d2)
{
	int dayDiff = dayOfYear(d2) - dayOfYear(d1);
	for (int y = d1.year; y < d2.year; ++y)
		for (int m = 1; m <= 12; ++m)
			dayDiff += monthLength(y, m);
	if (dayDiff < 0)
		dayDiff = -1;
	return dayDiff;
}

int main(void)
{
	Date since, to;
	cout <<  "Enter first date (y m d): ";
	cin >> since.year >> since.month >> since.day;
	cout <<  "Enter second date (y m d): ";
	cin >> to.year >> to.month >> to.day;
	cout << daysBetween(since, to) << endl;
	return 0;
}