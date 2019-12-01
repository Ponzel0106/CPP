#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

constexpr char DEFAULT_TRIMMING_CHARS[] = " \n\r";

std::string trim_left(std::string str,
	const std::string& chars = DEFAULT_TRIMMING_CHARS)
{
	if (const size_t beg = str.find_first_not_of(chars); beg != std::string::npos)
		str.erase(0, beg);
	return str;
}

std::string trim_right(std::string str,
	const std::string& chars = DEFAULT_TRIMMING_CHARS)
{
	if (const size_t last = str.find_last_not_of(chars); last != std::string::npos)
		str.erase(last + 1);
	return str;
}

std::string trim(std::string str,
	const std::string& chars = DEFAULT_TRIMMING_CHARS)
{
	return trim_left(trim_right(str, chars), chars);
}

class GymSubscription
{
public:
	GymSubscription();
	GymSubscription(int id_, const std::string& name_ = "Test", int month_ = 0);
	void printStatus() const;
	bool extendMembership(int nm);
	bool cancelMembership();
	// Getters
	int getId() const;
private:
	int id;
	int months;
	std::string name;
};

GymSubscription::GymSubscription()
	: id(0), months(0) // 0 - invalid id
{}

GymSubscription::GymSubscription(int id_, const std::string& name_, int months_)
	: id(id_), months(months_), name(name_)
{
	if (months < 0)
		months = 0;
}

void GymSubscription::printStatus() const
{
	std::cout << "Member " << id << " : " << name
		<< ", subscription valid for " << months << " months" << std::endl;
}

bool GymSubscription::extendMembership(int nm)
{
	if (nm < 0)
		return false;
	months += nm;
	return true;
}

bool GymSubscription::cancelMembership()
{
	months = 0;
	return true;
}

int GymSubscription::getId() const
{
	return id;
}

GymSubscription subs[10];

GymSubscription* findBookingById(int id)
{
	for (int i = 0; i < 10; ++i)
		if (subs[i].getId() == id)
			return subs + i;
	return nullptr;
}

void printBookings()
{
	std::cout << "**************************" << std::endl;
	bool exists = false;
	for (int i = 0; i < 10; ++i)
		if (subs[i].getId() != 0)
		{
			exists = true;
			subs[i].printStatus();
		}
	if (!exists)
		std::cout << "No subscriptions in the system" << std::endl;
	std::cout << "**************************" << std::endl;
}

int main()
{
	std::string line, command, name;
	int id, n;
	while (true)
	{
		std::cout << "What would you like to do?: ";
		getline(std::cin, line);

		std::stringstream comIss(line);
		comIss >> command;
		if (command == "quit")
			break;

		comIss >> id;
		if (id == 0)
		{
			std::cout << "Cannot perform this operation: Incorrect subscription ID" << std::endl;
			continue;
		}

		GymSubscription* const sub = findBookingById(id);
		bool success = false;
		if (command == "create")
		{
			if (sub)
			{
				std::cout << "Cannot perform this operation: Subscription ID already used" << std::endl;
				continue;
			}
			GymSubscription* const newSub = findBookingById(0);
			if (!newSub)
			{
				std::cout << "Cannot perform this operation: Too many subscriptions" << std::endl;
				continue;
			}
			std::getline(comIss, name);
			name = trim(name);
			
			*newSub = GymSubscription(id, name);
			success = true;
		}
		else
		{
			if (!sub)
			{
				std::cout << "Cannot perform this operation: Subscription "
					<< id << " not found" << std::endl;
				continue;
			}
			if (command == "extend")
			{
				comIss >> n;
				success = sub->extendMembership(n);
			}
			else if (command == "cancel")
				success = sub->cancelMembership();
			else if (command == "delete")
			{
				*sub = GymSubscription();
				success = true;
			}
		}
		if (!success)
			std::cout << "Cannot perform this operation" << std::endl;
		printBookings();
	}

	return 0;
}