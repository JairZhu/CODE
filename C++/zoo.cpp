#include "zoo.h"

Cat::Cat(string _name, int _age):Animal(_name, _age){}

Cat::~Cat()
{
}

void Cat::Shout() const
{
	cout << getName() << ':' << "meow~~" << endl;
}

Type Cat::getType() const
{
	return Type(CAT);
}

Dog::Dog(string _name, int _age):Animal(_name, _age){}

Dog::~Dog()
{
}

void Dog::Shout() const
{
	cout << getName() << ':' << "bark!!" << endl;
}

Type Dog::getType() const
{
	return Type(DOG);
}

Zoo::Zoo()
{
}

Zoo::~Zoo()
{
}

void Zoo::addAnimal(Animal * p)
{

	if (p->getType() == DOG) {
		for (int i = 0; i < dog.size(); ++i) {
			if (p->getName() == dog[i].getName() && p->getAge() == dog[i].getAge()) return;
		}
		Dog tmp(p->getName(), p->getAge());
		dog.push_back(tmp);
	}
	else {
		for (int i = 0; i < cat.size(); ++i) {
			if (p->getName() == cat[i].getName() && p->getAge() == cat[i].getAge()) return;
		}
		Cat tmp(p->getName(), p->getAge());
		cat.push_back(tmp);
	}
}

int Zoo::getDogCount()
{
	return dog.size();
}

int Zoo::getCatCount()
{
	return cat.size();
}

void Zoo::deleteAnimalByName(string name)
{
	for (int i = 0; i < cat.size(); ++i) {
		if (cat[i].getName() == name) {
			cat.erase(cat.begin() + i);
			i = 0;
		}
	}
	for (int i = 0; i < dog.size(); ++i) {
		if (dog[i].getName() == name) {
			dog.erase(dog.begin() + i);
			i = 0;
		}
	}
}

void Zoo::deleteAnimalByAge(int age)
{
	for (int i = 0; i < cat.size(); ++i) {
		if (cat[i].getAge() == age) {
			cat.erase(cat.begin() + i);
			i = 0;
		}
	}
	for (int i = 0; i < dog.size(); ++i) {
		if (dog[i].getAge() == age) {
			dog.erase(dog.begin() + i);
			i = 0;
		}
	}
}

void Zoo::print()
{
	for (int i = 0; i < dog.size(); ++i) {
		dog[i].Shout();
	}
	for (int i = 0; i < cat.size(); ++i) {
		cat[i].Shout();
	}
}
