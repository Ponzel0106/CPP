#include <iostream>

using namespace std;

int main(void)
{
	int system, foot;
	float meters, inch, foot_abs;
	cin >> system;
	if (system == 0)
	{
		cin >> meters;
		foot_abs = meters * 3.2808399f;
		foot = (int)foot_abs;
		inch = (foot_abs - foot) * 12.f;
		cout << foot << '\'' << inch << '"' << endl;
	}
	else if (system == 1)
	{
		cin >> foot >> inch;
		foot_abs = foot + inch / 12.f;
		meters = foot_abs / 3.2808399f;
		cout << meters << 'm' << endl;
	}
	else
		cout << "Incorrect system identifier!" << endl;
	return 0;
}