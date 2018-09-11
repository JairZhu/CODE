#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(long long num) {
	if (num == 2 || num == 3) return 1;
	if (num % 6 != 1 && num % 6 != 5) return 0;
	long long tmp = sqrt(num);
	for (long long i = 5; i <= tmp; i += 6)
		if (num % i == 0 || num % (i + 2) == 0)
			return 0;
	return 1;
}

int main() {
	long long n, m, sp, mstw, remain;
	vector<long long> edges;
	cin >> n >> m;
	for (long long i = n;; i++) {
		if (isPrime(i)) {
			sp = mstw = i;
			break;
		}
	}
	for (long long i = 0; i < n - 2; ++i) {
		edges.push_back(1);
	}
	edges.push_back(mstw - n + 2);
	remain = m - n + 1;
	cout << sp << ' ' << mstw << endl;
	for (long long i = 0; i < n - 1; ++i) {
		cout << i + 1 << ' ' << i + 2 << ' ' << edges[i] << endl;
	}
	for (long long i = 1; i < n; ++i) {
		for (long long j = i + 2; j < n + 1; ++j) {
			if (remain == 0) 
				return 0;
			cout << i << ' ' << j << ' ' << 1000000000 << endl;
			remain--;
		}
	}
	return 0;
}