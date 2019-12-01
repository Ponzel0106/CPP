#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void)
{
	bool good = true;
	int ip_parts[4];
	for (int i = 0; i < 4; ++i)
		if (!((cin >> ip_parts[i]) && 1 <= ip_parts[i] && ip_parts[i] <= 255))
		{
				good = false;
				break;
		}
	if (!good)
		cout << "Incorrect IP!" << endl;
	else
			cout << ip_parts[0] << '.' << ip_parts[1] << '.'
				 << ip_parts[2] << '.' << ip_parts[3] << endl;
	return 0;
}