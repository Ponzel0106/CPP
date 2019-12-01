#include <string>
#include <cctype>
#include <iostream>

int main()
{
	std::string pattern;
	std::getline(std::cin, pattern);

	std::string sentence;
	std::getline(std::cin, sentence);
	
	for (size_t i = 0; i <= sentence.size() - pattern.size(); ++i)
	{
		const std::string substr = sentence.substr(i, pattern.size());
		bool accepted = true;
		for (size_t j = 0; j < substr.size() && accepted; ++j)
				if (pattern[j] == 'D')
				{
					if (!isdigit(substr[j]))
						accepted = false;
				}
				else if (pattern[j] == 'A')
				{
					if (!isalpha(substr[j]))
						accepted = false;
				}
				else if (islower(pattern[j]))
				{
					if (pattern[j] != tolower(substr[j]))
						accepted = false;
				}
				else if (pattern[j] != '?')
				{
					if (pattern[j] != substr[j])
						accepted = false;
				}
		if (accepted)
			std::cout << substr << std::endl;
	}

	return 0;
}