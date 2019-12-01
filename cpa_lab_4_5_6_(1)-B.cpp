#include <string>
#include <iostream>

int main()
{
	std::string sentence;
	std::getline(std::cin, sentence);

		for (size_t i = 0; i < sentence.size() - 1; ++i)
			if (sentence[i] == ' ' && sentence[i + 1] == ' ')
				sentence.erase(i--, 1);

	std::cout << sentence << std::endl;
}