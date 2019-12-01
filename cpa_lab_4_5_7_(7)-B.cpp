#include <string>
#include <cctype>
#include <iostream>

using namespace std;

int main()
{
	string password;
	 getline(std::cin, password);

	bool valid = true;
	if (password.size() < 8)
	{
		cout << "The password must be at least 8 characters long" << endl;
		valid = false;
	}

	bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
	for (auto ch : password)
		if (isupper(ch))
			hasUpper = true;
		else if (islower(ch))
			hasLower = true;
		else if (isdigit(ch))
			hasDigit = true;
		else
			hasSpecial = true;
	valid &= (hasUpper && hasLower && hasDigit && hasSpecial);
		if (!hasUpper)
			cout << "The password must have at least one upper case letter" << endl;
		if (!hasLower)
			cout << "The password must have at least one lower case letter" << endl;
		if (!hasDigit)
			cout << "The password must have at least one digit" << endl;
		if (!hasSpecial)
			cout << "The password must have at least one special character" << endl;
		if (valid)
			cout << "The password is valid" << endl;

	return 0;
}