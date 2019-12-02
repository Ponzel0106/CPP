#include <iostream>
#include <string>

using namespace std;

// From 4_5_2_(1)
string correctIp(const string& s)
{
	constexpr int
		MAX_PART_CH_COUNT = 3,
		MAX_PART_VALUE = 255,
		VALID_PARTS = 4;
	int partCount = 1, partVal = 0, partChCount = 0;
	for (auto ch : s)
			if (ch == '.')
			{
				if (partChCount == 0)
					return "Part should not be empty";
				partChCount = 0, partVal = 0;
				if (++partCount > VALID_PARTS)
					return "Too many parts";
			}
			else if (isdigit(ch))
			{
				if (++partChCount > MAX_PART_CH_COUNT)
					return "Too many characters in a part";
				if ((partVal = 10 * partVal + (ch - '0')) > MAX_PART_VALUE)
					return "Too big a value of a part";
			}
			else
				return "Only digits and dots allowed";
	if (partCount < VALID_PARTS)
		return "Not enough parts";
	return "Correct IP";
}

class IPAddress
{
public:
		IPAddress(string ip);
		IPAddress(const IPAddress& ipAddress);
		virtual void print() const;
		string getIP(void) const;
private:
	string ip;
};

IPAddress::IPAddress(string ip)
	: ip(ip)
{}

IPAddress::IPAddress(const IPAddress & ipAddress)
	: ip(ipAddress.ip)
{}

void IPAddress::print() const
{
	cout << ip;
}

string IPAddress::getIP(void) const
{
	return ip;
}

class IPAddressChecked
	: public IPAddress
{
public:
	IPAddressChecked(string ip);
	IPAddressChecked(const IPAddressChecked& ipAddress);
	virtual void print() const override;
private:
	void check();

	bool correct;
};

IPAddressChecked::IPAddressChecked(string ip)
	: IPAddress(ip)
{
	check();
}

IPAddressChecked::IPAddressChecked(const IPAddressChecked& ipAddress)
	: IPAddress(ipAddress.getIP())
{
	check();
}

void IPAddressChecked::print() const
{
	IPAddress::print();
	cout << " - ";
	cout << (correct ? "Correct" : "Not Correct");
}

void IPAddressChecked::check()
{
	correct = (correctIp(getIP()) == "Correct IP");
}

int main()
{
	IPAddress* addresses[3];
	string ip;
	for (int i = 0; i < 3; ++i)
	{
		getline(cin, ip);
		if (i)
			addresses[i] = new IPAddressChecked(ip);
		else
			addresses[i] = new IPAddress(ip);
		addresses[i]->print();
		cout << endl; // Because print here is without endl
	}
	for (int i = 0; i < 3; ++i)
		delete addresses[i];
	return 0;
}
