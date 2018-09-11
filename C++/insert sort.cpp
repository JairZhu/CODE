void insert_sort(int *nums, int numsSize) {
	for (int i = 1; i < numsSize; ++i) {
		for (int j = i; j > 0; --j) {
			if (nums[j] < nums[j - 1]) {
				int tmp = nums[j];
				nums[j] = nums[j - 1];
				nums[j - 1] = tmp;
			}
		}
	}
}

int findKthLargest(int* nums, int numsSize, int k) {
	insert_sort(nums, numsSize);
	return nums[numsSize - k];
}