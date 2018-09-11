#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	long long n, k, l, m, index, remain, volumes = 0;
	vector<unsigned long long> staves;
	cin >> n >> k >> l;
	m = n * k;
	for (unsigned long long i = 0; i < m; ++i) {
		unsigned long long tmp;
		cin >> tmp;
		staves.push_back(tmp);
	}
	sort(staves.begin(), staves.end());
	if (staves[n - 1] - staves[0] > l) {
		cout << 0;
		return 0;
	}
	index = m - 1;
	for (unsigned long long i = 0; i < m; ++i) {
		if (staves[i] - staves[0] > l) {
			index = i - 1;
			break;
		}
	}
	remain = m - 1 - index;
	while (remain != 0 && remain >= k - 1) {
		volumes += staves[index];
		index--;
		remain -= k - 1;
	}
	if (index < 0) {
		cout << volumes;
		return 0;
	}
	while (index > k - 1) {
		index -= k - 1 - remain;
		remain = 0;
		volumes += staves[index];
		index--;
	}
	volumes += staves[0];
	cout << volumes;
	return 0;
}