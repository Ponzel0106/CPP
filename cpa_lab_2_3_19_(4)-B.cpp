#include <iostream>

using namespace std;

int main(void)
{
	double p = 1;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		p /= 2.;
	cout.precision(20);
	cout << p << endl;
	return 0;
}