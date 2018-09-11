double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int count = 0, total = nums1Size + nums2Size;
	int data[10000];
	if (nums1Size == 0 && nums2Size != 0) {
		if (total % 2 == 1) return (double)nums2[total / 2];
		else return (nums2[total / 2] + nums2[total / 2 - 1]) / 2.0;
	}
	else if (nums1Size != 0 && nums2Size == 0) {
		if (total % 2 == 1) return (double)nums1[total / 2];
		else return (nums1[total / 2] + nums1[total / 2 - 1]) / 2.0;
	}
	else {
		int p1 = 0, p2 = 0;
		while (count != total / 2 + 1) {
			if (p1 >= nums1Size)
				data[count++] = nums2[p2++];
			else if (p2 >= nums2Size)
				data[count++] = nums1[p1++];
			else if (p1 < nums1Size && p2 < nums2Size) {
				if (nums1[p1] < nums2[p2])
					data[count++] = nums1[p1++];
				else
					data[count++] = nums2[p2++];
			}
			else
				break;
		}
		if (total % 2 == 1) return (double)data[total / 2];
		else { 
			return (((double)data[total / 2 - 1] + (double)data[total / 2]) / 2.0);
		}
	}
}