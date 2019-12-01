#include <iostream>

using namespace std;

int main(void)
{
	unsigned long long p = 1;
	int n;
	cin >> n;
	if (n < 0 || 64 <= n)
	{
		cout << "Too large exponent!" << endl;
		return 0;
	}
	for (int i = 0; i < n; ++i)
		p *= 2;
	cout << p << endl;
	return 0;
}