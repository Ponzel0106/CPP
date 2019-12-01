#include <iostream>
#include <sstream>
#include <string>

class FlightBooking
{
public:
	FlightBooking();
	FlightBooking(int id, int capacity = 0, int reserved = 0);
	void printStatus() const;
	bool reserveSeats(int number_of_seats);
	bool cancelReservations(int number_of_seats);
	// Getters
	int getId() const;
private:
	int id;
	int capacity;
	int reserved;
};

FlightBooking::FlightBooking()
	: id(0), capacity(0), reserved(0) // 0 - invalid id
{}

FlightBooking::FlightBooking(int id_, int capacity_, int reserved_)
	: id(id_), capacity(capacity_), reserved(reserved_)
{
	if (capacity < 0)
		capacity = 0;
	if (reserved < 0)
		reserved = 0;
	if (reserved > capacity * 1.05)
		reserved = capacity * 1.05;
}

void FlightBooking::printStatus() const
{
	std::cout << "Flight " << id << " : " << reserved << '/' << capacity << " ("
		<< (int)((float)reserved / capacity * 100) << "%) seats taken" << std::endl;
}

bool FlightBooking::reserveSeats(int number_ob_seats)
{
	const int newSeats = reserved + number_ob_seats;
	if (number_ob_seats < 0 || newSeats > capacity * 1.05)
		return false;
	reserved = newSeats;
	return true;
}

bool FlightBooking::cancelReservations(int number_ob_seats)
{
	const int newSeats = reserved - number_ob_seats;
	if (number_ob_seats < 0 || newSeats < 0)
		return false;
	reserved = newSeats;
	return true;
}

int FlightBooking::getId() const
{
	return id;
}

FlightBooking bookings[10];

FlightBooking* findBookingById(int id)
{
	for (int i = 0; i < 10; ++i)
		if (bookings[i].getId() == id)
			return bookings + i;
	return nullptr;
}

void printBookings()
{
	std::cout << "**************************" << std::endl;
	bool exists = false;
	for (int i = 0; i < 10; ++i)
		if (bookings[i].getId() != 0)
		{
			exists = true;
			bookings[i].printStatus();
		}
	if (!exists)
		std::cout << "No flights in the system" << std::endl;
	std::cout << "**************************" << std::endl;
}

int main()
{
	std::string line, command;
	int id, n, cap;
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
			std::cout << "Cannot perform this operation: Incorrect flight ID" << std::endl;
			continue;
		}

		FlightBooking* const booking = findBookingById(id);
		bool success = false;
		if (command == "create")
		{
			if (booking)
			{
				std::cout << "Cannot perform this operation: Flight ID already used" << std::endl;
				continue;
			}
			FlightBooking* const newBooking = findBookingById(0);
			if (!newBooking)
			{
				std::cout << "Cannot perform this operation: Too many bookings" << std::endl;
				continue;
			}
			comIss >> cap;
			*newBooking = FlightBooking(id, cap);
			success = true;
		}
		else
		{
			if (!booking)
			{
				std::cout << "Cannot perform this operation: Flight "
					<< id << " not found" << std::endl;
				continue;
			}
			if (command == "add")
			{
				comIss >> n;
				success = booking->reserveSeats(n);
			}
			else if (command == "cancel")
			{
				comIss >> n;
				success = booking->cancelReservations(n);
			}
			else if (command == "delete")
			{
				*booking = FlightBooking();
				success = true;
			}
		}
		if (!success)
			std::cout << "Cannot perform this operation" << std::endl;
		printBookings();
	}

	return 0;
}