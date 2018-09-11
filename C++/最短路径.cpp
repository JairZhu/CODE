#include<iostream>
#include<queue>
using namespace std;

int labyrith[100][100];
int visited[100][100];
int edge[100][100];

int main() {
	int hight, width;
	cin >> hight >> width;
	for (int i = 1; i <= hight; ++i)
		for (int j = 1; j <= width; ++j)
			cin >> labyrith[i][j];
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	
}