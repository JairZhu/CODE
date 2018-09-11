#include <iostream>
#include <stack>
#include <map>
#include <set>	
#include <vector>
using namespace	std;

map<int, set<pair<int, double>>> Graph;
stack<int> top;
int marked[100000];

void dfs(int v) {
	marked[v] = 1;
	for (const pair<int, double> & edge : Graph[v]) {
		if (!marked[edge.first]) {
			dfs(edge.first);
		}
	}
	top.push(v);
}

int main() {
	int V, E, start;
	int edgeTo[10000];
	cin >> V >> E >> start;
	for (int i = 0; i < E; ++i) {
		int v, w;
		double weight;
		cin >> v >> w >> weight;
		Graph[v].insert(make_pair(w, weight));
	}
	vector<double> length;
	for (int i = 0; i <= V; ++i) length.push_back(INT_MAX);
	length[start] = 0;
	marked[start] = 1;
	for (const pair<int, double> & edge : Graph[start]) {
		if (!marked[edge.first]) {
			dfs(edge.first);
		}
	}
	top.push(start);
	while (!top.empty()) {
		int v = top.top();
		top.pop();
		for (const pair<int, double> & edge : Graph[v]) {
			int w = edge.first;
			if (length[w] > length[v] + edge.second) {
				length[w] = length[v] + edge.second;
				edgeTo[w] = v;
			}
		}
	}
	for (int i = 0; i < V; ++i) {
		cout << length[i] << endl;
	}
	return 0;
}