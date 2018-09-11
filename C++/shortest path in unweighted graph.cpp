#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int matrix[1000][1000];
bool visited[1000];
int len[1000];
int link[1000];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 1000; ++i)
		for (int j = 0; j < 1000; ++j) {
			matrix[i][j] = 0;
			visited[i] = false;
			len[i] = -1;
		}
	for (int i = 0; i < m; ++i) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		matrix[tmp1][tmp2] = 1;
		matrix[tmp2][tmp1] = 1;
	}
	queue<int> que;
	que.push(1);
	visited[1] = true;
	while (!que.empty()) {
		int visit = que.front();
		que.pop();
		for (int i = 1; i <= n; ++i) {
			if (matrix[visit][i] == 1 && !visited[i]) {
				que.push(i);
				link[i] = visit;
				visited[i] = true;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (visited[i]) {
			stack<int> path;
			for (int x = i; x != 1; x = link[x])
				path.push(x);
			path.push(1);
			len[i] = path.size() - 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << len[i] << ' ';
	}
	cout << endl;
	return 0;
}