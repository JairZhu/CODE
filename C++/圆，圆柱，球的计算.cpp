#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	double r, h, pi = 3.14;
	cin >> r >> h;
	printf("%.2f\n%.2f\n%.2f\n", pi * r * r, pi * r * r * h, 4.0 / 3.0 * pi * r * r * r);
	return 0;
}