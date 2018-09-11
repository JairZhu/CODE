#include <iostream>
#include <vector>
using namespace std;

int ans = 0, s = 0;
int n, m, c[100005], v[100005] = { 0 }, rec[100005 * 4];
vector<int> g[100005];

void set(int u) {
	c[u] ^= 1;
	rec[ans++] = u;
}

void dfs(int u) {
	set(u);
	v[u] = 1;
	for (int i = 0; i < g[u].size(); ++i) {
		if (v[g[u][i]]) continue;
		dfs(g[u][i]);
		set(u);
		if (c[g[u][i]]) {
			set(g[u][i]);
			set(u);
		}
	}
}

bool judge() {
	for (int i = 1; i <= n; ++i) 
		if (c[i]) return false;
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		if (c[i]) s = i;
	}
	dfs(s);
	if (c[s]) {
		c[s] = 0;
		ans--;
	}
	if (judge()) {
		cout << ans << endl;
		if (ans) {
			cout << rec[0];
			for (int i = 1; i < ans; ++i)
				cout << ' ' << rec[i];
			cout << endl;
		}
	}
	else
		cout << -1 << endl;
	return 0;
}