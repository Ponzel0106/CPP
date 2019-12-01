#include <iostream>
#include <string>

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

class Fraction
{
public:
	Fraction(int numerator = 1, int denominator = 1);
	std::string toString();
	double toDouble();
	// Operations
	Fraction plus(Fraction that);
	Fraction minus(Fraction that);
	Fraction times(Fraction that);
	Fraction by(Fraction that);
	// Comparisons
	bool isGreaterThan(Fraction that);
	bool isLessThan(Fraction that);
	bool isEqual(Fraction that);
private:
	void reduce();

	int numerator;
	int denominator;
};

Fraction::Fraction(int num, int den)
	: numerator(num), denominator(den)
{
	reduce();
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

Fraction Fraction::plus(Fraction that)
{
	int num = numerator * that.denominator + that.numerator * denominator;
	int den = denominator * that.denominator;

	Fraction result(num, den);
	result.reduce();
	return result;
}

Fraction Fraction::minus(Fraction that)
{
	int num = numerator * that.denominator - that.numerator * denominator;
	int den = denominator * that.denominator;

	Fraction result(num, den);
	result.reduce();
	return result;
}

Fraction Fraction::times(Fraction that)
{
	int num = numerator * that.numerator;
	int den = denominator * that.denominator;

	Fraction result(num, den);
	result.reduce();
	return result;
}

Fraction Fraction::by(Fraction that)
{
	int num = numerator * that.denominator;
	int den = denominator * that.numerator;

	Fraction result(num, den);
	result.reduce();
	return result;
}

bool Fraction::isGreaterThan(Fraction that)
{
	return minus(that).numerator > 0;
}

bool Fraction::isLessThan(Fraction that)
{
	return minus(that).numerator < 0;
}

bool Fraction::isEqual(Fraction that)
{
	return minus(that).numerator == 0;
}

void Fraction::reduce()
{
	const int g = gcd(numerator, denominator);
	numerator /= g, denominator /= g;
	if (denominator < 0)
		numerator = -numerator, denominator = -denominator;
}

int main(void)
{
	char delim;
	int num, den;
	Fraction fracts[2];
	
	for (int i = 0; i < 2; ++i)
	{
		std::cin >> num >> delim >> den;
		if (den == 0)
		{
			std::cout << "Denominator must not be zero!" << std::endl;
			return 0;
		}
		fracts[i] = Fraction(num, den);
	}

	if (fracts[0].isEqual(fracts[1]))
		std::cout << fracts[0].toString() << " = " << fracts[1].toString() << std::endl;
	else if (fracts[0].isLessThan(fracts[1]))
		std::cout << fracts[0].toString() << " < " << fracts[1].toString() << std::endl;
	else if (fracts[0].isGreaterThan(fracts[1]))
		std::cout << fracts[0].toString() << " > " << fracts[1].toString() << std::endl;
	else
		std::cout << "No comparison is true" << std::endl;
	return 0;
}