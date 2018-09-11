#include "Rational.h"
#include <iostream>
using namespace std;

string Rational::toString()
{
	char s[50];
	if (denominator == 1) {
		sprintf_s(s, "%ld", numerator);
	}
	else {
		sprintf_s(s, "%ld/%ld", numerator, denominator);
	}
	return string(s);
}

bool Rational::operator<(Rational & secondRational)
{
	if (compareTo(secondRational) < 0) return true;
	else return false;
}

bool Rational::operator<=(Rational & secondRational)
{
	if (compareTo(secondRational) <= 0) return true;
	else return false;
}

bool Rational::operator>(Rational & secondRational)
{
	if (compareTo(secondRational) > 0) return true;
	else return false;
}

bool Rational::operator>=(Rational & secondRational)
{
	if (compareTo(secondRational) >= 0) return true;
	else return false;
}

bool Rational::operator!=(Rational & secondRational)
{
	if (equals(secondRational)) return false;
	else return true;
}

bool Rational::operator==(Rational & secondRational)
{
	if (equals(secondRational)) return true;
	else return false;
}

Rational Rational::operator+(Rational & secondRational)
{
	return add(secondRational);
}

Rational Rational::operator-(Rational & secondRational)
{
	return subtract(secondRational);
}

Rational Rational::operator*(Rational & secondRational)
{
	return multiply(secondRational);
}

Rational Rational::operator/(Rational & secondRational)
{
	return divide(secondRational);
}

Rational Rational::operator+=(Rational & secondRational)
{
	*this = add(secondRational);
	return add(secondRational);
}

Rational Rational::operator-=(Rational & secondRational)
{
	*this = subtract(secondRational);
	return subtract(secondRational);
}

Rational Rational::operator*=(Rational & secondRational)
{
	*this = multiply(secondRational);
	return multiply(secondRational);
}

Rational Rational::operator/=(Rational & secondRational)
{
	*this = divide(secondRational);
	return divide(secondRational);
}

Rational Rational::operator++()
{
	Rational tmp(1, 1);
	*this = add(tmp);
	return *this;
}

Rational Rational::operator--()
{
	Rational tmp(1, 1);
	*this = subtract(tmp);
	return *this;
}

Rational Rational::operator++(int dummy)
{
	Rational tmp(numerator, denominator);
	Rational tmp1(1, 1);
	*this = add(tmp1);
	return tmp;
}

Rational Rational::operator--(int dummy)
{
	Rational tmp(numerator, denominator);
	Rational tmp1(1, 1);
	*this = subtract(tmp1);
	return tmp;
}

Rational Rational::operator+()
{
	return *this;
}

Rational Rational::operator-()
{
	return Rational(-numerator, denominator);
}

long & Rational::operator[](int i)
{
	if (i == 0) return numerator;
	else return denominator;
}

Rational::operator double()
{
	return doubleValue();
}

ostream & operator<<(ostream & stream, Rational & rational)
{
	cout << rational.toString();
	return stream;
}

istream & operator>>(istream & stream, Rational & rational)
{
	stream >> rational.numerator >> rational.denominator;
	return stream;
}

Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

Rational::Rational(long numerator1, long denominator1)
{
	numerator = numerator1;
	denominator = denominator1;
}

long Rational::getNumerator()
{
	return numerator;
}

long Rational::getDenominator()
{
	return denominator;
}

Rational Rational::add(Rational & secondRational)
{
	long tmp1 = numerator * secondRational.denominator + denominator * secondRational.numerator;
	long tmp2 = denominator * secondRational.denominator;
	if (tmp1 == 0 || tmp2 == 0) return Rational(tmp1, tmp2);
	long tmp3 = gcd(tmp1, tmp2);
	return Rational(tmp1 / tmp3, tmp2 / tmp3);
}

Rational Rational::subtract(Rational & secondRational)
{
	long tmp1 = numerator * secondRational.denominator - denominator * secondRational.numerator;
	long tmp2 = denominator * secondRational.denominator;
	long tmp3 = gcd(tmp1, tmp2);
	if (tmp1 == 0 || tmp2 == 0) return Rational(tmp1, tmp2);
	return Rational(tmp1 / tmp3, tmp2 / tmp3);
}

Rational Rational::multiply(Rational & secondRational)
{
	long tmp1 = numerator * secondRational.numerator;
	long tmp2 = denominator * secondRational.denominator;
	long tmp3 = gcd(tmp1, tmp2);
	if (tmp1 == 0 || tmp2 == 0) return Rational(tmp1, tmp2);
	return Rational(tmp1 / tmp3, tmp2 / tmp3);
}

Rational Rational::divide(Rational & secondRational)
{
	long tmp1 = numerator * secondRational.denominator;
	long tmp2 = denominator * secondRational.numerator;
	long tmp3 = gcd(tmp1, tmp2);
	if (tmp1 == 0 || tmp2 == 0) return Rational(tmp1, tmp2);
	return Rational(tmp1 / tmp3, tmp2 / tmp3);
}

int Rational::compareTo(Rational & secondRational)
{
	Rational tmp = subtract(secondRational);
	double n = 1.0 * tmp.getNumerator() / tmp.getDenominator();
	if (n > 0) return 1;
	else if (n < 0) return -1;
	else return 0;
	
}

bool Rational::equals(Rational & secondRational)
{
	return numerator == secondRational.numerator && denominator == secondRational.denominator;
}

int Rational::intValue()
{
	return numerator / denominator;
}

double Rational::doubleValue()
{
	return 1.0 * numerator / denominator;
}

long Rational::gcd(long n, long d)
{
	if (n == 0 || d == 0) return 0;
	if (n > d) {
		while (n % d != 0) {
			long tmp = n % d;
			n = d;
			d = tmp;
		}
		return d;
	}
	else if (n < d) {
		while (d % n != 0) {
			long tmp = d % n;
			d = n;
			n = tmp;
		}
		return n;
	}
	else return n;
}
