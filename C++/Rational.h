#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <string>
using namespace std;
class Rational {
public:
	Rational();
	Rational(long numerator, long denominator);
	long getNumerator();
	long getDenominator();
	Rational add(Rational &secondRational);
	Rational subtract(Rational &secondRational);
	Rational multiply(Rational &secondRational);
	Rational divide(Rational &secondRational);
	int compareTo(Rational &secondRational);
	bool equals(Rational &secondRational);
	int intValue(); //Returns the numerator/denominator
	double doubleValue(); //Returns 1.0*numberator/denominator
	string toString();
	bool operator<(Rational &secondRational);
	bool operator<=(Rational &secondRational);
	bool operator>(Rational &secondRational);
	bool operator>=(Rational &secondRational);
	bool operator!=(Rational &secondRational);
	bool operator==(Rational &secondRational);
	Rational operator+(Rational &secondRational);
	Rational operator-(Rational &secondRational);
	Rational operator*(Rational &secondRational);
	Rational operator/(Rational &secondRational);
	Rational operator+=(Rational &secondRational);
	Rational operator-=(Rational &secondRational);
	Rational operator*=(Rational &secondRational);
	Rational operator/=(Rational &secondRational);
	Rational operator++();
	Rational operator--();
	Rational operator++(int dummy);
	Rational operator--(int dummy);
	Rational operator+();
	Rational operator-();
	long& operator[] (int);
	friend ostream &operator<<(ostream &stream, Rational &rational);
	friend istream &operator>>(istream &stream, Rational &rational);
	operator double();
private:
	long numerator; //©{?¨GÜ‡.
	long denominator; //©{???©S?2??°î?a0.
	static long gcd(long n, long d);
};
#endif