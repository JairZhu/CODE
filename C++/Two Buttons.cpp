#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (m < n) {
		cout << n - m;
		return 0;
	}
	int count = 0;
	while (m != n) {
		if (m % 2 == 1) {
			m++;
			count++;
		}
		else {
			if (m > n) {
				m /= 2;
				count++;
			}
			if (m < n) {
				m++;
				count++;
			}
		}
	}
	cout << count;
	return 0;
}