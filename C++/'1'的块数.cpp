#include <iostream>
using namespace std;

int matrix[100][100];
int visited[100][100];

void block(int i, int j, int count) {
	if (matrix[i][j] == 1 && visited[i][j] == -1) {
		visited[i][j] = count;
		if (matrix[i][j + 1] == 1 && visited[i][j + 1] == -1) {
			block(i, j + 1, count);
		}
		if (matrix[i + 1][j] == 1 && visited[i + 1][j] == -1) {
			block(i + 1, j, count);
		}
		if (matrix[i + 1][j + 1] == 1 && visited[i + 1][j + 1] == -1) {
			block(i + 1, j + 1, count);
		}
		if (i != 0 && matrix[i - 1][j] == 1 && visited[i - 1][j] == -1) {
			block(i - 1, j, count);
		}
		if (j != 0 && matrix[i][j - 1] == 1 && visited[i][j - 1] == -1) {
			block(i, j - 1, count);
		}
		if (i != 0 && j != 0 && matrix[i - 1][j - 1] && visited[i - 1][j - 1] == -1) {
			block(i - 1, j - 1, count);
		}
		if (i != 0 && matrix[i - 1][j + 1] == 1 && visited[i - 1][j + 1] == -1) {
			block(i - 1, j + 1, count);
		}
		if (j != 0 && matrix[i + 1][j - 1] == 1 && visited[i + 1][j - 1] == -1) {
			block(i + 1, j - 1, count);
		}
	}
}

int main() {
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j) {
			matrix[i][j] = 0;
			visited[i][j] = -1;
		}
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> matrix[i][j];
	int count = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (matrix[i][j] == 1 && visited[i][j] == -1) ++count;
			block(i, j, count);
		}
	cout << count;
	return 0;
}