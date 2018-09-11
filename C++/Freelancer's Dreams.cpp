#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int a[100010], b[100010];
int n, p, q;

double find(double x) {
	double y = 1;
	for (int i = 0; i < n; ++i)
		y = min(y, (1.0 - x * b[i]) / a[i]);
	return y * p + x * q;
}

int main() {
	cin >> n >> p >> q;
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];
	double l = 0, r = 1.0 / (*max_element(b, b + n));
	for (int i = 0; i < 50; i++) {
		double ll = (r + l) * 0.5, rr = (ll + r) * 0.5;
		if (find(ll) > find(rr)) r = rr;
		else l = ll;
	}
	cout << fixed << setprecision(10) << find((l + r) * 0.5);
	return 0;
}