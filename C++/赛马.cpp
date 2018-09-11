#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int number;
	cin >> number;
	if (number % 2 == 1) {
		cout << "NO";
		return 0;
	}
	int data1[100];
	int data2[100];
	for (int i = 0; i < number; ++i)
		cin >> data1[i];
	for (int i = 0; i < number; ++i)
		cin >> data2[i];
	int count = 0;
	sort(data1, data1 + number);
	sort(data2, data2 + number);
	bool suc = true;
	for (int i = 0; i < number / 2; ++i) {
		if (data1[i] > data2[i + number / 2]) suc = false;
	}
	for (int i = number / 2; i < number; ++i) {
		if (data1[i] < data2[i - number / 2]) suc = false;
	}
	if (suc) cout << "YES";
	else cout << "NO";
	return 0;
}