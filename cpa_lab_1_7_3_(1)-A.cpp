#include <iostream>
#include <iomanip>

using namespace std;
constexpr int precisions[5] = { 1, 2, 6, 2, 0 };

int main(void)
{
	float a[5];
	for (int i = 0; i < 5; ++i)
		 cin >> a[i];
	cout << fixed;
	for (int i = 0; i < 5; ++i)
		 cout << setprecision(precisions[i]) << a[i] << endl;
	return 0;
}