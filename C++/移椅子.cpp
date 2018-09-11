#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, m;
		cin >> n >> m;
		list<int> data;
		for (int j = 1; j <= n; ++j) {
			data.push_back(j);
		}
		for (int j = 0; j < m; ++j) {
			int tmp1, tmp2, tmp3;
			cin >> tmp1 >> tmp2 >> tmp3;
			if (tmp1 == 1) {
				auto p1 = find(data.begin(), data.end(), tmp2);
				data.erase(p1);
				auto p2 = find(data.begin(), data.end(), tmp3);
				data.insert(p2, tmp2);
			}
			else {
				auto p1 = find(data.begin(), data.end(), tmp2);
				data.erase(p1);
				auto p2 = find(data.begin(), data.end(), tmp3);
				data.insert(++p2, tmp2);
			}
		}
		for (auto j : data)
			cout << j << ' ';
		cout << endl;
	}
	return 0;
}