#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;

int main() {
	int V, E, start;
	cin >> V >> E >> start;
	map<int, set<pair<int, double>>> Graph;
	int onqueue[100000] = { 0 };
	int edgeto[100000];
	for (int i = 0; i < E; ++i) {
		int v, w;
		double weight;
		cin >> v >> w >> weight;
		Graph[v].insert(make_pair(w, weight));
	}
	vector<double> length;
	for (int i = 0; i < V; ++i) length.push_back(INT_MAX);
	length[start] = 0;
	queue<int> que;
	que.push(start);
	onqueue[start] = 1;
	while (!que.empty()) {
		int v = que.front();
		que.pop();
		onqueue[v] = 0;
		for (const pair<int, double> &edge : Graph[v]) {
			int w = edge.first;
			if (length[w] > length[v] + edge.second) {
				length[w] = length[v] + edge.second;
				edgeto[w] = v;
				if (!onqueue[w]) {
					que.push(w);
					onqueue[w] = 1;
				}
			}
		}
	}
	for (int i = 0; i < V; ++i)
		cout << length[i] << endl;
	return 0;
}