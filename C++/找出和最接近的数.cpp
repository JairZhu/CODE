#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int number;
	int data[10000] = { 0 };
	int target;
	cin >> number;
	for (int i = 0; i < number; ++i)
		cin >> data[i];
	cin >> target;
	int sum[10000];
	int count = 0;
	for (int i = 0; i < number - 2; ++i) {
		for (int j = i + 1; j < number - 1; ++j) {
			for (int k = j + 1; k < number; ++k) {
				sum[count++] = data[i] + data[j] + data[k];
			}
		}
	}
	int min = abs(sum[0] - target);
	int index = 0;
	for (int i = 0; i < count; ++i) {
		if (min > abs(sum[i] - target)) {
			min = abs(sum[i] - target);
			index = i;
		}
	}
	cout << sum[index];
}