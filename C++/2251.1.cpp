#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main() {
	int num;
	cin >> num;
	char tmp[10000], arr[10000];
	for (int i = 0; i<num; ++i) {
		cin >> tmp;
		int s = 0;
		for (int j = 0; j<strlen(tmp); ++j) {
			if (tmp[j] != '_') {
				arr[s++] = tmp[j];
				if (j == strlen(tmp) - 1) {
					int k = s - 1;
					while (k != -1) {
						cout << arr[k--];
					}
				}
			}
			else if (tmp[j] = '_') {
				int k = s - 1;
				while (k != -1) {
					cout << arr[k--];
				}
				cout << '_';
				for (int m = 0; m<s; ++m)
					arr[m] = 0;
				s = 0;
			}

		}
		cout << endl;
		for (int m = 0; m<1000; ++m)
			arr[m] = 0;
	}
}
