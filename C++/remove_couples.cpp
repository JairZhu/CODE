#include <iostream>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int j = 0; j < T; ++j) {
		int N;
		cin >> N;
		queue<int> couples;
		for (int i = 0; i < 2 * N; ++i) {
			couples.push(i + 1);
		}
		int arr[100000];
		for (int i = 0; i < N; ++i) {
			int a, b;
			cin >> a >> b;
			arr[a] = b;
			arr[b] = a;
		}
		for (int i = 0; i < 2 * N; ++i) {
			if (couples.empty()) break;
			int a = couples.front();
			couples.pop();
			if (arr[a] == couples.front())
				couples.pop();
			else 
				couples.push(a);
		}
		if (couples.empty()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}