#include <iostream>

using namespace std;

int main(void) {

	int vector[] = { 1, 7, 3, 8, 3, 7, 1 };
	bool ispalindrome = true;
	const int n = sizeof(vector) / sizeof(vector[0]);

	for (int i = 0, j = n - 1; i < j; ++i, --j)
		if (vector[i] != vector[j])
		{
			ispalindrome = false;
			break;
		}

	if (ispalindrome)
		cout << "It's a palindrome";
	else
		cout << "It isn't a palindrome";
	cout << endl;
	return 0;
}