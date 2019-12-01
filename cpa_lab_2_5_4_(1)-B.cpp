#include <iostream>

using namespace std;

int main(void)
{
	int op;
	double a, b, res;
	while (true)
	{
		cout << "MENU:" << endl;
		cout << "0 - exit\n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division" << endl;
		cout << "Your choice?" << endl;

		cin >> op;
		if (op == 0)
			break;
		if (op < 0 || 4 < op)
		{
			cout << "Invalid operation, try again." << endl;
			continue;
		}

		cout << "Enter first number: ";
		cin >> a;
		cout << "Enter second number: ";
		cin >> b;
		switch (op)
		{
		case 1: res = a + b; break;
		case 2: res = a - b; break;
		case 3: res = a * b; break;
		case 4: res = a / b; break;
		default: res = 0.; // Should not happen
		}

		cout << "Result: " << res << endl;
	}

	return 0;
}