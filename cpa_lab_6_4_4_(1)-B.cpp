#include <iostream>
#include <string>

class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(const std::string& input) = 0;
};

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

class DummyValidator
	: public StringValidator {
public:
	virtual bool isValid(const std::string& input) override;
};

bool DummyValidator::isValid(const std::string& input)
{
	return true;
}

using namespace std;

void printValid(StringValidator& validator, const std::string& input)
{
	cout << "The string '" << input << "' is "
		<< (validator.isValid(input) ? "valid" : "invalid") << endl;
}

int main()
{
	DummyValidator dummy;
	printValid(dummy, "hello");
	cout << endl;

	ExactValidator exact("secret");
	printValid(exact, "hello");
	printValid(exact, "secret");
	return 0;
}