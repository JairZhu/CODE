#include <iostream>
using namespace std;

int main() {
	int number;
	cin >> number;
	int height[1000] = { 0 };
	for (int i = 0; i < number; ++i)
		cin >> height[i];
	int count = 0;
	for (int i = 1; i < number - 1; ++i) {
		int lhigh = 0;
		int rhigh = 0;
		for (int j = i; j >= 0; --j) {
			if (height[j] > lhigh) lhigh = height[j];
		}
		for (int j = i; j < number; ++j) {
			if (height[j] > rhigh)	rhigh = height[j];
		}
		if ((lhigh - height[i]) > 0 && (rhigh - height[i]) > 0) count += (lhigh < rhigh ? lhigh : rhigh) - height[i];
	}
	cout << count;
	return 0;
}