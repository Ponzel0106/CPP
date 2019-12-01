#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(void)
{
	int ch[256] = {};
	string s;
	getline(cin, s);
	for (size_t i = 0; i < s.size(); ++i)
		++ch[tolower(s[i])];
	bool isPangram = true;
	for (char x = 'a'; x <= 'z'; ++x)
		if (!ch[x])
			isPangram = false;
	cout << (isPangram ? "Pangram " : "Not pangram ") << endl;
	for (char x = 'a'; x <= 'z'; ++x)
		cout << x << '-' << ch[x] << endl;
	return 0;
}