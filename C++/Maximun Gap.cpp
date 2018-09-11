#include <iostream>
using namespace std;

int partition(int *nums, int low, int high) {
	int i = low, j = high + 1;
	int v = nums[low];
	while (true) {
		while (nums[++i] < v) if (i == high) break;
		while (nums[--j] > v) if (j == low) break;
		if (j <= i) break;
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	nums[low] = nums[j];
	nums[j] = v;
	return j;
}

void quicksort(int *nums, int low, int high) {
	if (low >= high) return;
	int k = partition(nums, low, high);
	quicksort(nums, low, k - 1);
	quicksort(nums, k + 1, high);
}

int maximumGap(int* nums, int numsSize) {
	if (numsSize < 2) return 0;
	quicksort(nums, 0, numsSize - 1);
	int max = -1;
	for (int i = 0; i < numsSize - 1; ++i) {
		if (nums[i + 1] - nums[i] > max) max = nums[i + 1] - nums[i];
	}
	return max;
}

int main() {
	int nums[] = { 100, 3, 2, 1 };
	int size = 4;
	cout << maximumGap(nums, size);
	return 0;
}