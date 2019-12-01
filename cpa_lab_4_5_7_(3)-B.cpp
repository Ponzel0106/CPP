#include <string>
#include <cctype>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	std::string stop_words, stop_word, word, lower_word;
	std::getline(std::cin, stop_words);

	std::string sentence;
	std::getline(std::cin, sentence);
	
	std::vector<std::string> swords;
	std::istringstream sw_iss(stop_words);
	while (std::getline(sw_iss, stop_word, ','))
	{
		std::transform(stop_word.begin(), stop_word.end(),
			stop_word.begin(), tolower);
		swords.push_back(stop_word);
	}

	std::istringstream iss(sentence);
	std::ostringstream oss;
	while (iss >> word)
	{
		lower_word = word;
		std::transform(lower_word.begin(), lower_word.end(),
			lower_word.begin(), tolower);
		if (std::find(swords.begin(), swords.end(), lower_word) == swords.end())
			oss << word << ' ';
	}
	sentence = oss.str();

	std::cout << sentence << std::endl;

	return 0;
}