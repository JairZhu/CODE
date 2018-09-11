#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long n, l, x, r;
	int count = 0;
	vector<long> problems;
	cin >> n >> l >> r >> x;
	for (long i = 0; i < n; ++i) {
		long tmp;
		cin >> tmp;
		problems.push_back(tmp);
	}
	sort(problems.begin(), problems.end());
	for (int i = 0; i < pow(2, n); ++i) {
		long sum = 0, mini = LONG_MAX, maxi = -1;
		for (int j = 0; j < problems.size(); ++j) {
			if (i & 1 << j) {
				sum += problems[j];
				mini = min(problems[j], mini);
				maxi = max(problems[j], maxi);
			}
		}
		if (sum >= l && sum <= r && maxi - mini >= x) count++;
	}
	cout << count;
	return 0;
}