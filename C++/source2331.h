template <typename T>
int find_lower_bound(T seq[], int n, const T& value) {
	T tmp;
	int index = -1;
	for (int i = n - 1; i >= 0; --i) {
		if (seq[i] < value) {
			tmp = seq[i];
			index = i;
		}
	}
	if (index == -1) return -1;
	for (int i = 0; i < n; ++i) {
		if (seq[i] < value && tmp < seq[i]) {
			tmp = seq[i];
			index = i;
		}
	}
	return index;
}