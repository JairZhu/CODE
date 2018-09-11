#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	char s[2], t[2];
	cin >> s >> t;
	int x = t[0] - s[0], y = t[1] - s[1];
	int diagonal = min(abs(x), abs(y));
	int step = max(abs(x), abs(y));
	int side = step - diagonal;
	cout << step << endl;
	if (diagonal != 0 && x > 0 && y < 0) {
		for (int i = 0; i < diagonal; ++i) {
			cout << "RD" << endl;
		}
	}
	else if (diagonal != 0 && x > 0 && y > 0) {
		for (int i = 0; i < diagonal; ++i) {
			cout << "RU" << endl;
		}
	}
	else if (diagonal != 0 && x < 0 && y < 0) {
		for (int i = 0; i < diagonal; ++i) {
			cout << "LD" << endl;
		}
	}
	else if (diagonal != 0 && x < 0 && y > 0) {
		for (int i = 0; i < diagonal; ++i) {
			cout << "LU" << endl;
		}
	}
	if (side != 0) {
		if (abs(x) > abs(y)) {
			if (x > 0) {
				for (int i = 0; i < side; ++i) {
					cout << 'R' << endl;
				}
			}
			else {
				if (x < 0) {
					for (int i = 0; i < side; ++i) {
						cout << 'L' << endl;
					}
				}
			}
		}
		else if (abs(x) < abs(y)) {
			if (y > 0) {
				for (int i = 0; i < side; ++i) {
					cout << 'U' << endl;
				}
			}
			else if (y < 0) {
				for (int i = 0; i < side; ++i) {
					cout << 'D' << endl;
				}
			}
		}
	}
	return 0;
}
