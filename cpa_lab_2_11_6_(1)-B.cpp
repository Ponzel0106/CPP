#include <iostream>

using namespace std;

struct Time
{
	int hours;
	int minutes;
};

int main(void)
{
	Time t;
	cin >> t.hours >> t.minutes;
	if (!(0 <= t.minutes && t.minutes < 60 && 0 <= t.hours && t.hours <= 24))
	{
		cout << "Incorrect time!" << endl;
		return 0;
	}
	int duration;
	cin >> duration;
	const int res_min = (t.hours * 60 + t.minutes + duration) % (24 * 60);
	t.hours = res_min / 60, t.minutes = res_min % 60;
	cout << t.hours << ':' << t.minutes << endl;
	return 0;
}