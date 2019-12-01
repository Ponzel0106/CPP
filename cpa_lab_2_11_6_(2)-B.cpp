#include <iostream>

using namespace std;

struct Time
{
	int hours;
	int minutes;
};

int main(void)
{
	Time t1, t2;
	cin >> t1.hours >> t1.minutes >> t2.hours >> t2.minutes;
	if (!(0 <= t1.hours && t1.hours < 24 && 0 <= t1.minutes && t1.minutes < 60))
	{
		cout <<  "First time point is incorrect!" << endl;
		return 0;
	}
	if (!(0 <= t2.hours && t2.hours < 24 && 0 <= t2.minutes && t2.minutes < 60))
	{
		cout <<  "Second time point is incorrect!" << endl;
		return 0;
	}
	if (!(t1.hours < t2.hours || t1.hours == t2.hours && t1.minutes < t2.minutes))
	{ 
		cout <<  "Second time point should be later!" << endl;
		return 0;
	}
	const int res = (t2.hours - t1.hours) * 60 + (t2.minutes - t1.minutes);
	cout << res / 60 << ':' << res % 60 << endl;
	return 0;
}