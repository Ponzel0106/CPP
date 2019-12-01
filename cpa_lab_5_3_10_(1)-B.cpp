#include <iostream>

class FlightBooking
{
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
private:
	int id;
	int capacity;
	int reserved;
};

void FlightBooking::printStatus()
{
	std::cout << "Flight " << id << " : " << reserved << '/' << capacity << " ("
		<< (int)((float)reserved / capacity * 100) << "%) seats taken" << std::endl;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
	: id(id), capacity(capacity), reserved(reserved)
{}

int main() {
	int reserved = 0,
		capacity = 0;
	std::cout << "Provide flight capacity: ";
	std::cin >> capacity;

	std::cout << "Provide number of reserved seats: ";
	std::cin >> reserved;

	FlightBooking booking(1, capacity, reserved);

	booking.printStatus();

	return 0;
}