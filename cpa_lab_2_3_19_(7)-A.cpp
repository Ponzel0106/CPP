#include <iostream>

using namespace std;

int main(void)
{
	unsigned long long n, prev = 0, cur = 1, temp;
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
			temp = cur + prev;
			prev = cur;
			cur = temp;
	}
	cout << cur << endl;
	return 0;
}