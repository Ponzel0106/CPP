#include <string>
#include <iostream>

std::string spacify(const std::string& s)
{
	std::string ret = " ";
	for (size_t i = 0; i < s.size(); ++i)
	{
		ret.push_back(s[i]);
		ret.push_back(' ');
	}
	return ret;
}

std::string toupper(std::string s)
{
	for (auto& ch : s)
		ch = toupper(ch);
	return s;
}

int main()
{
	std::string sentence, res, temp;
	std::getline(std::cin, sentence);

	int state = 0; // 0 - nothing opened, 1 - '*' opened, 2 - '_' opened
	for (size_t i = 0; i < sentence.size(); ++i)
	{
		const char cur = sentence[i];
		if (cur == '_')
		{
			if (state == 0)
				state = 2;
			else if (state == 1)
				state = 2, res += temp, temp.clear();
			else
				state = 0, res += spacify(temp), temp.clear();
		}
		else if (cur == '*')
		{
			if (state == 0)
				state = 1;
			else if (state == 1)
				state = 0, res += toupper(temp), temp.clear();
			else
				state = 1, res += temp, temp.clear();
		}
		else
		{
			if (state == 0)
				res.push_back(cur);
			else
				temp.push_back(cur);
		}
	}
	if (state)
		res += temp;

	std::cout << res << std::endl;
}