#include <iostream>

using namespace std;

int main(void)
{
	int year, month, day;
	cin >> year >> month >> day;
	month -= 2;
	if (month <= 0) // !!! <= !!!
		month += 12, --year;
	cout << (month * 83 / 32 + day
		+ year + year / 4 - year / 100 + year / 400) % 7 << endl;
	return 0;
}