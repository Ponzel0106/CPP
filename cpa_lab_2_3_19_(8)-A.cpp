#include <iostream>

using namespace std;

int main(void)
{
	int n;
	unsigned long long fact = 1;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		fact *= i;
	cout << fact << endl;
	return 0;
}