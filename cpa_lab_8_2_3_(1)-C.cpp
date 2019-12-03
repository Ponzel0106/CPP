#include <iostream>
#include <string>

using namespace std;

enum WeekDay
{
	Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday,
	WEEKDAY_COUNT
};

enum Month
{
	January, February, March, April, May, June,
	July, August, September, October, November, December,
	MONTH_COUNT
};

class Date
{
public:
	static constexpr int MONTH_DAYS_COMMON[MONTH_COUNT] = {
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	static inline const string MONTH_STR[MONTH_COUNT] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December",
	};
	static inline const string WEEKDAY_STR[MONTH_COUNT] = {
		"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
	};
	static bool isLeapYear(int year)
	{
		if (year % 400 == 0)
			return true;
		if (year % 100 == 0)
			return false;
		if (year % 4 == 0)
			return true;
		return false;
	}
	static int yearDays(int year)
	{
		return isLeapYear(year) ? 366 : 365;
	}
	static int monthDays(int year, Month month)
	{
		return MONTH_DAYS_COMMON[month]
			+ (month == February && isLeapYear(year));
	}

	Date(int y, Month m, int d)
	{
		if (y < 1970)
			throw std::invalid_argument(
				"Year must not be less than 1970");
		if (!(0 <= m && m < MONTH_COUNT))
			throw std::invalid_argument(
				"Month must be within range [0-"
				+ to_string(MONTH_COUNT) + ")");
		const int mDays = monthDays(y, m);
		if (!(0 <= d && d < mDays))
			throw std::invalid_argument(
				"Day of " + MONTH_STR[m] + " must be within range [0-"
				+ to_string(mDays) + ")");

		year = y, month = m, day = d;
	}
	int daysSinceTheStart() const
	{
		int days = day;
		for (int y = 1970; y < year; ++y)
			days += yearDays(y);
		for (int m = 0; m < month; ++m)
			days += monthDays(year, (Month)(m));
		return days;
	}
	WeekDay weekday() const
	{
		return (WeekDay)((daysSinceTheStart() + 4) % 7);
	}
	void print()
		{
			cout << day + 1 << ' ' << MONTH_STR[month] << ' ' << year << " - "
				 << WEEKDAY_STR[weekday()] << " - " << daysSinceTheStart()
				 << " days since 1st January 1970" << endl;
	}
private:
	 int year;
	 Month month; // 0-based
	 int day; // of month, 0-based
};

int main(void)
{
	int year, month, day;
	if (!(cin >> day >> month >> year))
	{
		cout << "Bad input" << endl;
		return 0;
	}
	try
	{
		Date date(year, (Month)(--month), --day);
		date.print();
	}
	catch (const exception & ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}