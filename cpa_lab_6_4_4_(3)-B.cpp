#include <iostream>
#include <string>

class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(const std::string& input) const = 0;
};


class DummyValidator
	: public StringValidator {
public:
	virtual bool isValid(const std::string& input) const override;
};

bool DummyValidator::isValid(const std::string& input) const
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
	virtual bool isValid(const std::string& input) const override;
private:
	std::string match;
};


bool ExactValidator::isValid(const std::string& input) const
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
	virtual bool isValid(const std::string& input) const override;
private:
	int threshold;
};

bool MinLengthValidator::isValid(const std::string& input) const
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
	virtual bool isValid(const std::string& input) const override;
private:
	int threshold;
};

bool MaxLengthValidator::isValid(const std::string& input) const
{
	return input.size() <= threshold;
}

class LengthValidator
	: public StringValidator
{
public:
	LengthValidator(int min, int max);
	virtual bool isValid(const std::string& input) const override;
private:
	MinLengthValidator min_validator;
	MaxLengthValidator max_validator;
};

LengthValidator::LengthValidator(int min, int max)
	: min_validator(min), max_validator(max)
{}

bool LengthValidator::isValid(const std::string& input) const
{
	return (min_validator.isValid(input)
		&& max_validator.isValid(input));
}

class PatternValidator
	: public StringValidator
{
public:
	PatternValidator(const std::string& pattern)
		: pattern(pattern)
	{}
	virtual bool isValid(const std::string& input) const override;
private:
	std::string pattern;
};

bool PatternValidator::isValid(const std::string& input) const
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

class AtLeastValidator
	: public StringValidator
{
public:
	AtLeastValidator(const std::string& specifiers = "D")
		: specifiers(specifiers)
	{}
	virtual bool isValid(const std::string& input) const override;
private:
	std::string specifiers;
};

bool AtLeastValidator::isValid(const std::string& input) const
{
	bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
	for (auto ch : input)
		if (isupper(ch))
			hasUpper = true;
		else if (islower(ch))
			hasLower = true;
		else if (isdigit(ch))
			hasDigit = true;
		else
			hasSpecial = true;
	for (char spec : specifiers)
		switch (spec)
		{
		case 'U': if (!hasUpper) return false; break;
		case 'L': if (!hasLower) return false; break;
		case 'D': if (!hasDigit) return false; break;
		case 'S': if (!hasSpecial) return false; break;
		}
	return true;
}

class PasswordValidator
	: public StringValidator
{
public:
	PasswordValidator()
		: lengthValidator(8, 8), alValidator("ULDS")
	{}
	virtual bool isValid(const std::string& input) const override;
private:
	LengthValidator lengthValidator;
	AtLeastValidator alValidator;
};

bool PasswordValidator::isValid(const std::string& input) const
{
	return lengthValidator.isValid(input)
		&& alValidator.isValid(input);
}

using namespace std;

void printValid(StringValidator& validator, const std::string& input)
{
	cout << "The string '" << input << "' is "
		<< (validator.isValid(input) ? "valid" : "invalid") << endl;
}

int main()
{
	string password;
	cin >> password;
	PasswordValidator passValidator;
	cout << boolalpha << passValidator.isValid(password) << endl;
	return 0;
}
