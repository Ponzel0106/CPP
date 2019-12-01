#include <string>
#include <sstream>
#include <iostream>

int main()
{
	std::string sentence, word, prev_word;
	std::getline(std::cin, sentence);

	std::istringstream iss(sentence);
	std::ostringstream oss;
	while (iss >> word)
	{
		if (word.find_first_of(".,!?;:") != std::string::npos
			|| word != prev_word)
			oss << word << ' ';
		prev_word = word;
	}
	sentence = oss.str();

	std::cout << sentence << std::endl;
}