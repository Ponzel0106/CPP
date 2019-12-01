#include <iostream>

using namespace std;

int main(void)
{
	int n, b1, b2, d;
	cout << "Enter pyramid height please: ";
	cin >> n;
	d = 2 * n; // between centers of pyramids
	for (int i = 0; i < n; ++i)
	{
		int j = 0, center = 0;
		for (int pyr = 0; pyr < 3; ++pyr)
		{
			center = n - 1 + pyr * d;
			if (i == 0)
			{
				while (j++ < center)
					cout << ' ';
				cout << '*';
			}
			else if (i == n - 1)
			{
				while (j++ < center + n)
					cout << '*';
				cout << ' '; // or --j
			}
			else
			{
				b1 = center - i, b2 = center + i; // relative to enclosing rect
				while (j++ < b1)
					cout << ' ';
				cout << '*';
				while (j++ < b2)
					cout << ' ';
				cout << '*';
			}
		}
		cout << endl;
	}
	return 0;
}