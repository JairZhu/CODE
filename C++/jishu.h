#include<iostream>
#include<queue>
using namespace std;

void radixsort(int data[], int n) {
	queue<int> que[10];
	for (int i = 0; i < n; ++i)
		que[data[i] % 10].push(data[i]);
	int count = 0;
	for (int i = 0; i < 10; ++i) {
		while (!que[i].empty()) {
			data[count++] = que[i].front();
			que[i].pop();
		}
	}
	int tmp = 0;
	for (int i = 0; i < n; ++i) {
		que[data[i] / 10].push(data[i]);
	}
	count = 0;
	for (int i = 0; i < 10; ++i) {
		while (!que[i].empty()) {
			data[count++] = que[i].front();
			que[i].pop();
		}
	}
}