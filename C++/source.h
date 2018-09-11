#include <iostream>
using namespace std;

class Person
{
public:
	Person();
	~Person();
	virtual string toString() { return "Person"; }
private:

};

Person::Person()
{
}

Person::~Person()
{
}

class Student: public Person
{
public:
	Student();
	~Student();
	virtual string toString() { return "Student"; }
private:

};

Student::Student()
{
}

Student::~Student()
{
}

class Employee: public Person
{
public:
	Employee();
	~Employee();
	virtual string toString() { return "Employee"; }
private:

};

Employee::Employee()
{
}

Employee::~Employee()
{
}

class Staff: public Employee
{
public:
	Staff();
	~Staff();
	string toString() { return "Staff"; }
private:

};

Staff::Staff()
{
}

Staff::~Staff()
{
}

class Faculty: public Employee
{
public:
	Faculty();
	~Faculty();
	string toString() { return "Fcaulty"; }
private:

};

Faculty::Faculty()
{
}

Faculty::~Faculty()
{
}