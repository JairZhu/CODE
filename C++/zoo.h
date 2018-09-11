#ifndef zoo_h
#define zoo_h

#include "animal.h"

class Cat: public Animal
{
public:
	Cat(string _name = "", int _age = 0);
	~Cat();
	void Shout() const;
	Type getType() const;

private:

};

class Dog: public Animal
{
public:
	Dog(string _name = "", int _age = 0);
	~Dog();
	void Shout() const;
	Type getType() const;

private:

};

class Zoo
{
public:
	Zoo();
	~Zoo();
	void addAnimal(Animal * p);
	int getDogCount();
	int getCatCount();
	void deleteAnimalByName(string name);
	void deleteAnimalByAge(int age);
	void print();

private:
	vector<Cat> cat;
	vector<Dog> dog;
};

#endif