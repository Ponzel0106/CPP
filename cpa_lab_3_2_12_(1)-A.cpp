#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
	int n = sizeof(vector) / sizeof(vector[0]), mn = numeric_limits<int>::max();

	int* p = vector;
	while (n--)
		mn = std::min(mn, *p++);

	cout << mn << endl;

	return 0;
}