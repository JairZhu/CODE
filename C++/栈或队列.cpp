#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int number;
	cin >> number;
	int in[100] = { 0 };
	int out[100] = { 0 };
	for (int i = 0; i < number; ++i) cin >> in[i];
	for (int i = 0; i < number; ++i) cin >> out[i];
	stack<int> sta;
	queue<int> que;
	for (int i = 0; i < number; ++i) {
		sta.push(in[i]);
		que.push(in[i]);
	}
	bool is_stack = true;
	bool is_queue = true;
	for (int i = 0; i < number; ++i) {
		if (sta.top() != out[i]) is_stack = false;
		sta.pop();
		if (que.front() != out[i]) is_queue = false;
		que.pop();
	}
	if (is_stack && !is_queue) cout << "stack";
	if (!is_stack && is_queue) cout << "queue";
	if (is_stack && is_queue) cout << "both";
	if (!is_stack && !is_queue) cout << "neither";
	return 0;
}