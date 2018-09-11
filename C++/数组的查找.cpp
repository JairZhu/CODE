#include<iostream>
using namespace std;

int main() {
	int arr[5];
	for (int i = 0; i < 5; ++i) {
		cin >> arr[i];
	}
	int test;
	bool flag = false;
	cin >> test;
	for (int i = 0; i < 5; ++i) {
		if (arr[i] == test) {
			cout << i << endl;
			flag = true;
		}
	}
	if (!flag) cout << -1 << endl;
	return 0;
}