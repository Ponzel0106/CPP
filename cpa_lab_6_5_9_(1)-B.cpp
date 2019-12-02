#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Body
{
public:
	Body(const string& color)
		: color(color)
	{}
	void print() const;
private:
	string color;
};


void Body::print() const
{
	cout << "Body: " << color << endl;
}


class Light
{
public:
	Light(const std::string& type = "Type 0")
		: type(type)
	{}
	void print() const;
private:
	std::string type;
};

void Light::print() const
{
	cout << "Light: " << type << endl;
}


class Chassis
{
public:
	Chassis(const std::string& type)
		: type(type)
	{}
	void print() const;
private:
	std::string type;
};

void Chassis::print() const
{
	cout << "Chassis: " << type << endl;
}

class Wheel
{
public:
	Wheel(int inches = 10)
		: inches(inches)
	{}
	void print() const;
private:
	int inches;
};

void Wheel::print() const
{
	cout << "Wheel: " << inches << " inches" << endl;
}

class Engine
{
public:
	Engine(int horsepowers)
		: horsepowers(horsepowers)
	{}
	void print() const;
private:
	int horsepowers;
};

void Engine::print() const
{
	cout << "Engine: " << horsepowers << " horse powers" << endl;
}

class Car
{
public:
	static constexpr size_t WHEEL_COUNT = 4;
	static constexpr size_t LIGHT_COUNT = 10;
	Car(Engine engine, Chassis chassis,
		Body body, Wheel whls[WHEEL_COUNT], Light ls[LIGHT_COUNT])
		: engine(engine), chassis(chassis), body(body)
	{
		for (size_t i = 0; i < WHEEL_COUNT; ++i)
			wheels[i] = whls[i];
		for (size_t i = 0; i < LIGHT_COUNT; ++i)
			lights[i] = ls[i];
	}
	void print() const;
private:
	Engine engine;
	Chassis chassis;
	Body body;
	Wheel wheels[WHEEL_COUNT];
	Light lights[LIGHT_COUNT];
};

void Car::print() const
{
	engine.print();
	for (const auto& wheel : wheels)
		wheel.print();
	chassis.print();
	for (const auto& light : lights)
		light.print();
	body.print();
}

int main()
{
	Light lights[10];
	Wheel wheels[4] = { Wheel(16), Wheel(16), Wheel(16), Wheel(16) };
	for (size_t i = 0; i < 10; ++i)
		lights[i] = Light("Type " + to_string(i / 2 + 1));
	Car c(
		Engine(500),
		Chassis("Normal"),
		Body("Black"),
		wheels,
		lights
	);
	c.print();
	return 0;
}
