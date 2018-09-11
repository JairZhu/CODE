#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	int count = 0;
	while (num != 0) {
		if (num != (num / 2 ) * 2) count++;
		num = num / 2;
	}
	cout << count;
	return 0;
}