#include <iostream>
using namespace std;

int main() {
	int arr[10];
	for (int i = 0; i < 10; i++)
		cin >> arr[i];
	int target;
	cin >> target;
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 10; ++j) {
			if (arr[i] + arr[j] == target) {
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
}