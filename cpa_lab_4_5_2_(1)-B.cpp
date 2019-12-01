#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string correctIp(const string& s)
{
	constexpr int
		MAX_PART_CH_COUNT = 3,
		MAX_PART_VALUE = 255,
		VALID_PARTS = 4;
	int partCount = 1, partVal = 0, partChCount = 0;
	for (auto ch : s)
		if (ch == '.')
		{
			if (partChCount == 0)
				return "Part should not be empty";
			partChCount = 0, partVal = 0;
			if (++partCount > VALID_PARTS)
				return "Too many parts";
		}
		else if (isdigit(ch))
		{
			if (++partChCount > MAX_PART_CH_COUNT)
				return "Too many characters in a part";
			if ((partVal = 10 * partVal + (ch - '0')) > MAX_PART_VALUE)
				return "Too big a value of a part";
		}
		else
			return "Only digits and dots allowed";
	if (partCount < VALID_PARTS)
		return "Not enough parts";
	return "Correct IP";
}

int main(void)
{
	string s;
	while (true)
	{
		cout << "Enter IP please (or 0 to exit): " << endl;
		cin >> s;
		if (s == "0")
			break;
		cout << correctIp(s) << endl;
	}
	return 0;
}