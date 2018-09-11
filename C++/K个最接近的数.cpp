#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int number;
	cin >> number;
	int data[10000];
	for (int i = 0; i < number; ++i)
		cin >> data[i];
	int count, target;
	cin >> count >> target;
	int distance_count[10000] = { 0 };
	queue<int> que[10000];
	for (int i = 0; i < number; ++i) {
		distance_count[abs(target - data[i])]++;
		que[abs(target - data[i])].push(data[i]);
	}
	int out[10000];
	int inc = 0;
	for (int i = 0; i < 10000; i++) {
		if (distance_count[i] != 0 && count != 0) {
			while (!que[i].empty() && count != 0) {
				out[inc++] = que[i].front();
				que[i].pop();
				count--;
			}
		}
	}
	sort(out, out + inc);
	for (int i = 0; i < inc - 1; ++i) {
		cout << out[i] << ' ';
	}
	cout << out[inc - 1];
	return 0;
}