#include <iostream>
#include <string>
#include <vector>

using namespace std;

class IPAddress
{
public:
	IPAddress(string ip);
	IPAddress(const IPAddress& ipAddress);
	virtual void print() const;
private:
	string ip;
};


IPAddress::IPAddress(string ip)
	: ip(ip)
{}

IPAddress::IPAddress(const IPAddress& ipAddress)
	: ip(ipAddress.ip)
{}

void IPAddress::print() const
{
	cout << ip << endl;
}


class Network
{
public:
	void add(const IPAddress& ip);
	void print() const;
private:
	vector<IPAddress> ips;
};

void Network::add(const IPAddress& ip)
{
	ips.push_back(ip);
}

void Network::print() const
{
	for (const auto& ip : ips)
		ip.print();
}

int main()
{
	string ip_str;
	Network nets[2];
	for (int i = 0; i < 5; ++i)
	{
		getline(cin, ip_str);
		if (i <= 2)
			nets[0].add(ip_str);
		if (i >= 2)
			nets[1].add(ip_str);
	}
	for (int i = 0; i < 2; ++i)
	{
		cout << "Network " << i << ':' << endl;
		nets[i].print();
	}
	return 0;
}
