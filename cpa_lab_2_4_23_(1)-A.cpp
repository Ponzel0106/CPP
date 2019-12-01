#include <iostream>

using namespace std;

int main(void)
{
		unsigned long long n, res(0);
		cin >> n;
		while (n)
			res += (n & 1), n >>= 1;
		cout << res << endl;
}