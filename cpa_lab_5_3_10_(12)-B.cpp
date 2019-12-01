#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class FarmAnimal
{
public:
	FarmAnimal(double water_consumption);
	double getWaterConsumption() const;
protected:
	void setWaterConsumption(double cons);
private:
	double water_consumption;
};

FarmAnimal::FarmAnimal(double water_consumption)
	: water_consumption(water_consumption)
{}

double FarmAnimal::getWaterConsumption() const
{
	return water_consumption;
}

void FarmAnimal::setWaterConsumption(double cons)
{
	water_consumption = cons;
}

void printConsumption(FarmAnimal& animal)
{
	cout << "This animal consumes " << animal.getWaterConsumption()
		<< " liters of water" << endl;
}

class Horse
	: public FarmAnimal
{
public:
	Horse(double weight);
};

Horse::Horse(double weight)
	: FarmAnimal(6.8 * weight / 100.)
{}

class Sheep
	: public FarmAnimal
{
public:
	Sheep(double weight);
};

Sheep::Sheep(double weight)
	: FarmAnimal(1.1 * weight / 10.)
{}

class Cow
	: public FarmAnimal
{
public:
	Cow(double weight);
};

Cow::Cow(double weight)
	: FarmAnimal(8.6 * weight / 100.)
{}

class ConsumptionAccumulator
{
public:
	ConsumptionAccumulator();
	double getTotalConsumption();
	void addConsumption(FarmAnimal& animal);
private:
	double total_consumption;
};

ConsumptionAccumulator::ConsumptionAccumulator() :
	total_consumption(0)
{}

double ConsumptionAccumulator::getTotalConsumption()
{
	return total_consumption;
}

void ConsumptionAccumulator::addConsumption(FarmAnimal& animal)
{
	total_consumption += animal.getWaterConsumption();
}

int main()
{
	ConsumptionAccumulator accumulator;

	string line, animal;
	double weight;
	while (true)
	{
		getline(cin, line);
		istringstream iss(line);
		if (!(iss >> animal))
			break;
		iss >> weight;
		FarmAnimal* an = nullptr;
		if (animal == "horse")
			an = new Horse(weight);
		else if (animal == "sheep")
			an = new Sheep(weight);
		else if (animal == "cow")
			an = new Cow(weight);
		if (an == nullptr)
			continue; // Ignore unknown animals
		accumulator.addConsumption(*an);
		delete an;
	}

	cout << accumulator.getTotalConsumption() << endl;

	return 0;
}