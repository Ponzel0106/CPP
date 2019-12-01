#include <iostream>

using namespace std;

int main(void)
{
	int i, j, k;

		cout << "Enter i: ";
		cin >> i;
		cout << "Enter j: ";
		cin >> j;

		i += 2;
		j -= i;
		k = i / j;
		k += k;
		--k;
		j = k % i;
		k += k + i;
		k += k / j;
		k = k * k * k;
		k += i * j;

	cout << k << endl;
	return 0;
}