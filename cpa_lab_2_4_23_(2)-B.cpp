#include <iostream>

using namespace std;

int main(void) {

	unsigned short val;
	bool ispalindrome = true;

	cout << "Enter value please: ";
	cin >> val;

	for (unsigned short i = 0, j = 15; i < j && ispalindrome; --j, ++i)
		ispalindrome &= ((bool)(val & (1 << i)) == (bool)(val & (1 << j)));

	if (ispalindrome)
		cout << val << " is a bitwise palindrome" << endl;
	else
		cout << val << " is not a bitwise palindrome" << endl;
	return 0;
}