#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
		string name;
		int    age;
		string passportNumber;
		double height; //  meter
};

void print(Person* person)
{
		cout << person->name << " is " << person->age << " years old" << endl;
}

int main()
		{
		Person person;
		person.name = "Harry";
		person.age = 23;
		person.passportNumber = "23764912369";
		person.height = 1.76;

		cout << "Meet " << person.name << endl;
		print(&person);

		cout << "His passport number is: " << person.passportNumber << endl;
		cout << "His height in meters is " << person.height << endl;

		return 0;
}