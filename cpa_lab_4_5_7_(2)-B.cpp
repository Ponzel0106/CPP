#include <string>
#include <iostream>

int main()
{
	std::string from;
	std::getline(std::cin, from);

	std::string to;
	std::getline(std::cin, to);

	std::string sentence;
	std::getline(std::cin, sentence);

	size_t fpos = 0;
	while ((fpos = sentence.find(from, fpos)) != std::string::npos)
	{
		sentence.replace(fpos, from.size(), to);
		fpos += to.size();
	}

	std::cout << sentence << std::endl;
}