#include <iostream>
#include <string>

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

class Fraction
{
public:
	Fraction(int numerator, int denominator);
	std::string toString();
	double toDouble();
private:
	int numerator;
	int denominator;
};

Fraction::Fraction(int num, int den)
{
	const int g = /*gcd(num, den)*/ 1;
	numerator = num / g, denominator = den / g;
	if (denominator < 0)
		numerator = -numerator, denominator = -denominator;
}

std::string Fraction::toString()
{
	std::string ret;
	int num = numerator, den = denominator;
	if (numerator < 0)
		ret.push_back('-'), num = -numerator;

	int whole = num / den;
	if (whole)
		ret += std::to_string(whole);

	num -= whole * den;
	if (num)
		ret += (whole ? " " : "") + std::to_string(num) + '/' + std::to_string(den);

	return ret;
}

double Fraction::toDouble()
{
	return (double)numerator / denominator;
}

int main(void)
{
	char delim;
	int num, den;
	
	std::cin >> num >> delim >> den;
	if (den == 0)
	{
		std::cout << "Denominator must not be zero!" << std::endl;
		return 0;
	}
	Fraction fraction(num, den);

	std::cout << fraction.toString() << " is "
		<< fraction.toDouble() << " in decimal" << std::endl;
	return 0;
}