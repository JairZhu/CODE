bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
	int x = 0, y = 0;
	while (true) {
		if (matrixColSize == 0 && matrixRowSize == 0) return false;
		if (matrix[x][y] == target) return true;
		else if (x + 1 < matrixRowSize && y + 1 < matrixColSize && matrix[x + 1][y + 1] <= target) {
			++x;
			++y;
		}
		else if (x + 1 < matrixRowSize && matrix[x + 1][y] <= target) {
			++x;
		}
		else if (y + 1 < matrixColSize && matrix[x][y + 1] <= target) {
			++y;
		}
		else {
			if (x + 1 == matrixRowSize) return false;
			for (int i = 1; true; ++i) {
				if (y - i < 0) return false;
				if (matrix[x + 1][y - i] <= target) {
					++x;
					y -= i;
					break;
				}
			}
		}
	}
}