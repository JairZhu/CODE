#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;

class Object
{
public:
	Object();
	~Object();
	virtual void fuck_dynamic_cast() = 0;
private:

};

Object::Object()
{
}

Object::~Object()
{
}

class Animal: virtual public Object 
{
public:
	Animal();
	~Animal();
	virtual void fuck_dynamic_cast() {};
private:

};

Animal::Animal()
{
}

Animal::~Animal()
{
}

class Dog: virtual public Animal
{
public:
	Dog();
	~Dog();
	void fuck_dynamic_cast() {};
private:

};

Dog::Dog()
{
}

Dog::~Dog()
{
}

class Cat: virtual public Animal
{
public:
	Cat();
	~Cat();
	void fuck_dynamic_cast() {};
private:

};

Cat::Cat()
{
}

Cat::~Cat()
{
}

class Vehicle: virtual public Object
{
public:
	Vehicle();
	~Vehicle();
	virtual void fuck_dynamic_cast() {};
private:

};

Vehicle::Vehicle()
{
}

Vehicle::~Vehicle()
{
}

class Bus: virtual public Vehicle
{
public:
	Bus();
	~Bus();
	void fuck_dynamic_cast() {};
private:

};

Bus::Bus()
{
}

Bus::~Bus()
{
}

class Car:virtual  public Vehicle
{
public:
	Car();
	~Car();
	void fuck_dynamic_cast() {};
private:

};

Car::Car()
{
}

Car::~Car()
{
}

string instanceOf(Object *obj) {
	if (obj == NULL) return "NULL";
	if (typeid(*obj) == typeid(Object)) return "Object";
	if (typeid(*obj) == typeid(Vehicle)) return "Vehicle";
	if (typeid(*obj) == typeid(Animal)) return "Animal";
	if (typeid(*obj) == typeid(Dog)) return "Dog";
	if (typeid(*obj) == typeid(Cat)) return "Cat";
	if (typeid(*obj) == typeid(Bus)) return "Bus";
	if (typeid(*obj) == typeid(Car)) return "Car";
}