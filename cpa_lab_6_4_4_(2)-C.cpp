#include <iostream>
#include <string>

class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(const std::string& input) = 0;
};

class DummyValidator
	: public StringValidator {
public:
	virtual bool isValid(const std::string& input) override;
};


bool DummyValidator::isValid(const std::string& input)
{
	return true;
}


class ExactValidator
	: public StringValidator
{
public:
	ExactValidator(const std::string& match)
		: match(match)
	{}
	virtual bool isValid(const std::string& input) override;
private:
	std::string match;
};


bool ExactValidator::isValid(const std::string& input)
{
	return input == match;
}


class MinLengthValidator
	: public StringValidator
{
public:
	MinLengthValidator(int threshold)
		: threshold(threshold)
	{}
	virtual bool isValid(const std::string& input) override;
private:
	int threshold;
};

bool MinLengthValidator::isValid(const std::string& input)
{
	return input.size() >= threshold;
}

class MaxLengthValidator
	: public StringValidator
{
public:
	MaxLengthValidator(int threshold)
		: threshold(threshold)
	{}
	virtual bool isValid(const std::string& input) override;
private:
	int threshold;
};

bool MaxLengthValidator::isValid(const std::string& input)
{
	return input.size() <= threshold;
}

class PatternValidator
	: public StringValidator
{
public:
	PatternValidator(const std::string& pattern)
		: pattern(pattern)
	{}
	virtual bool isValid(const std::string& input);
private:
	std::string pattern;
};

bool PatternValidator::isValid(const std::string& input)
{
	for (size_t i = 0; i <= input.size() - pattern.size(); ++i)
	{
		const std::string substr = input.substr(i, pattern.size());
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
			return true;
	}
	return false;
}

using namespace std;

void printValid(StringValidator& validator, const std::string& input)
{
	cout << "The string '" << input << "' is "
		<< (validator.isValid(input) ? "valid" : "invalid") << endl;
}

int main()
{
	cout << "MinLengthValidator" << endl;
	MinLengthValidator min(6);
	printValid(min, "hello");
	printValid(min, "welcome");
	cout << endl;

	cout << "MaxLengthValidator" << endl;
	MaxLengthValidator max(6);
	printValid(max, "hello");
	printValid(max, "welcome");
	cout << endl;

	cout << "PatternValidator" << endl;
	PatternValidator digit("D");
	printValid(digit, "there are 2 types of sentences in the world");
	printValid(digit, "valid and invalid ones");
	cout << endl;

	return 0;
}