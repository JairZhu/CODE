#include <iostream>
#include <string>
using namespace std;

int main() {
	string arr;
	cin >> arr;
	for (int i = 0; i < arr.length() / 2; ++i) {
		char tmp = arr[i];
		arr[i] = arr[arr.length() - 1 - i];
		arr[arr.length() - 1 - i] = tmp;
	}
	cout << arr;
	bool flag = true;
	while (flag) {
		if (!(cin >> arr)) {
			break;
		}
		else cout << ' ';
		for (int i = 0; i < arr.length() / 2; ++i) {
			char tmp = arr[i];
			arr[i] = arr[arr.length() - 1 - i];
			arr[arr.length() - 1 - i] = tmp;
		}
		cout << arr;
	}
	return 0;
}