int partition(int *nums, int low, int high) {
	int i = low, j = high + 1;
	int v = nums[low];
	while (true) {
		while (v > nums[++i])
			if (i == high)
				break;
		while (v < nums[--j])
			if (j == low)
				break;
		if (j <= i)
			break;
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	nums[low] = nums[j];
	nums[j] = v;
	return j;
}

void quick_sort(int *nums, int low, int high) {
	if (low >= high) return;
	int j = partition(nums, low, high);
	quick_sort(nums, low, j - 1);
	quick_sort(nums, j + 1, high);
}

