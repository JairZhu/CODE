#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int p, q;
	int P[100000] = {0};
	int Q[100000] = {0};
	cin >> p >> q;
	int n1 = 0;  
	int n2 = 0;
	int tmp = p > q ? p : q;
	for (int i = 1; i < sqrt(tmp * 1.0) + 1; ++i) {
		if (p == 1) {
			P[0] = 1;
			n1 = 1;
		}
		else if (p > i && p!= i && p % i == 0) {
			P[n1++] = i;
			if (p / i != i) P[n1++] = p / i;
		}
		if (q == 1) {
			Q[0] = 1;
			n2 = 1;
		}
		if (q > i && q != i && q % i == 0) {
			Q[n2++] = i;
			if (q / i != i) Q[n2++] = q / i;
		}
	}
	tmp = n1 < n2 ? n2 : n1;
	for (int i = 0; i < tmp - 1; ++i) {
		if (i < n1) {
			for (int j = i + 1; j < n1; ++j) {
				if (P[i] > P[j]) {
					int a = P[i];
					P[i] = P[j];
					P[j] = a;
				}
			}
		}
		if (i < n2) {
			for (int j = i + 1; j < n2; ++j) {
				if (Q[i] > Q[j]) {
					int a = Q[i];
					Q[i] = Q[j];
					Q[j] = a;
				}
			}
		}
	}
	for (int i = 0; i < n1; ++i) {
		for (int j = 0; j < n2; ++j) {
			cout << P[i] << ' ' << Q[j] << endl;
		}
	}
	system("pause");
}