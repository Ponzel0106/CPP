#include <iostream>
#include <sstream>
#include <string>

class FlightBooking
{
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus() const;
	bool reserveSeats(int number_of_seats);
	bool cancelReservations(int number_of_seats);
private:
	int id;
	int capacity;
	int reserved;
};

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

int main()
{
	int reserved = 0,
		capacity = 0;
	std::cout << "Provide flight capacity: ";
	std::cin >> capacity;

	std::cout << "Provide number of reserved seats: ";
	std::cin >> reserved;

	FlightBooking booking(1, capacity, reserved);

	int cnt;
	std::string line, command;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (true)
	{
			booking.printStatus();
			std::cout << "What would you like to do?: ";
			getline(std::cin, line);

			std::stringstream comIss(line);
			comIss >> command;
			if (command == "quit")
				break;

			comIss >> cnt;
			bool success = false;
			if (command == "add")
				success = booking.reserveSeats(cnt);
			else if (command == "cancel")
				success = booking.cancelReservations(cnt);
			if (!success)
				std::cout << "Cannot perform this operation" << std::endl;
	}

	return 0;
}