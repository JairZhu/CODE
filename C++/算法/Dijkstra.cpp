#include<map>
#include<set>
#include<iostream>
#include<vector>
using namespace std;

double Dijkstra() {
	int V, E, start, dest;
	cin >> V >> E >> start >> dest;
	map<int, set<pair<int, double>>> Graph;
	for (int i = 0; i < E; ++i) {
		int v, w;
		double weight;
		cin >> v >> w >> weight;
		Graph[v].insert(make_pair(w, weight));
	}
	vector<double> Lenth;
	for (int i = 0; i <= V; ++i) Lenth.push_back(INT_MAX);
	Lenth[start] = 0;
	set<int> S;
	while (!S.count(dest)) {
		int min = V;
		for (int i = 0; i < V; ++i)
			if (!S.count(i) && Lenth[i] < Lenth[min]) min = i;
		S.insert(min);
		for (const pair<int, double> & edge : Graph[min]) {
			int v = edge.first;
			if (!S.count(v)) {
				double len = edge.second;
				double newlen = len + Lenth[min];
				Lenth[v] = newlen < Lenth[v] ? newlen : Lenth[v];
			}
		}
	}
	return Lenth[dest];
}