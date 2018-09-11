#include <iostream>
#include <queue>
using namespace std;

int matrix[2000][2000];
bool visited[200];

void bfs(int start, int cities) {
	queue<int> que;
	que.push(start);
	visited[start] = true;
	while (!que.empty()) {
		int tmp = que.front();
		que.pop();
		for (int i = 0; i < cities; ++i) {
			if (matrix[tmp][i] == 1 && !visited[i]) {
				que.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {
	while (true) {
		int cities, roads;
		cin >> cities;
		if (cities == 0) return 0;
		for (int i = 0; i < 2000; ++i)
			for (int j = 0; j < 2000; ++j)
				matrix[i][j] = 0;
		for (int i = 0; i < 200; ++i)
			visited[i] = false;
		cin >> roads;
		for (int i = 0; i < roads; ++i) {
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			matrix[tmp1][tmp2] = 1;
			matrix[tmp2][tmp1] = 1;
		}
		bfs(0, cities);
		if (visited[cities - 1]) cout << "I can post the letter\n";
		else cout << "I can't post the letter\n";
	}
	return 0;
}