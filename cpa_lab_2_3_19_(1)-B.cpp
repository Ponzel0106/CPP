#include <iostream>

using namespace std;

int main(void)
{
	int n, steps(0);
	cin >> n;
	while (n != 1)
	{
		if (n % 2)
			 n = n * 3 + 1;
		else
			 n /= 2;
		cout << n << ' ';
		++steps;
	}
	cout << "steps = " << steps << endl;
	return 0;
}