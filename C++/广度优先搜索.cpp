#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;

int main() {
	int number, start;
	int data[100][100];
	int visit[100] = { 0 };
	queue<int> que;
	int count = 0;
	cin >> number >> start;
	for (int i = 1; i <= number; ++i)
		for (int j = 1; j <= number; ++j)
			cin >> data[i][j];
	cout << start << ' ';
	count++;
	visit[start] = 1;
	for (int i = 1; i <= number; ++i) {
		if (data[start][i] != 0) {
			cout << i;
			if (count != number - 1) cout << ' ';
			count++;
			que.push(i);
			visit[i] = 1;
		}
	}
	while (!que.empty()) {
		int tmp = que.front();
		que.pop();
		for (int i = 1; i <= number; ++i) {
			if (data[tmp][i] != 0 && visit[i] == 0) {
				cout << i;
				if (count != number - 1) cout << ' ';
				count++;
				que.push(i);
				visit[i] = 1;
			}
		}
	}
	return 0;
}