#include <iostream>
using namespace std;

int robots(int m, int n) {
	if (m <= 0 || n <= 0) return 0;
	else if (m == 1 && n == 1) return 1;
	else return robots(m - 1, n) + robots(m, n - 1);
}

int main() {
	int test;
	cin >> test;
	for (int i = 0; i < test; ++i) {
		int m, n;
		cin >> m >> n;
		cout << robots(m, n) << endl;
	}
	return 0;
}