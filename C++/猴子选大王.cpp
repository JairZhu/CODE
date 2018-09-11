#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, m;
		cin >> n >> m;
		queue<int> monkeyking;
		for (int j = 0; j < n; ++j) {
			monkeyking.push(j + 1);
		}
		while (monkeyking.size() != 1) {
			for (int j = 0; j < m - 1; ++j) {
				int tmp = monkeyking.front();
				monkeyking.pop();
				monkeyking.push(tmp);
			}
			monkeyking.pop();
		}
		cout << monkeyking.front() << endl;
	}
	return 0;
}