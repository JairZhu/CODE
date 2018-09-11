#include <iostream>
using namespace std;

int partition(int *data, int low, int high) {
	int i = low, j = high + 1;
	int v = data[low];
	while (true) {
		while (v > data[++i]) if (i >= high) break;
		while (v < data[--j]) if (j <= low) break;
		if (i >= j) break;
		int tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	}
	data[low] = data[j];
	data[j] = v;
	return j;
}

void sort(int *data, int low, int high) {
	if (low >= high) return;
	int k = partition(data, low, high);
	sort(data, low, k - 1);
	sort(data, k + 1, high);
}

int main() {
	int n, data[1000];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> data[i];
	sort(data, 0, n - 1);
	for (int i = 0; i < n; ++i)
		cout << data[i] << endl;
	return 0;
}