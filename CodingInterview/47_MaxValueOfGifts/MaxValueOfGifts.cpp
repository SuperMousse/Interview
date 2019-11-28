// 解法一: 动态规划->循环初步解法

int getMaxValue_solution1(vector<vector<int> > values) {
	if (values.empty()) {
		return 0;
	}
	int rows = values.size();
	int cols = values[0].size();

	vector<vector<int> > maxValues(rows, vector<int>(cols, 0));

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			int left = 0;
			int up = 0;

			if (i > 0) {
				up = maxValues[i - 1][j];
			}
			if (j > 0) {
				left = maxValues[i][j - 1];
			}
			maxValues[i][j] = max(left, up) + values[i][j];
		}
	}
	int maxValue = maxValues[rows - 1][cols - 1];

	return maxValue;
}


// 解法二: 动态规划->循环优化解法


int getMaxValue_solution2(vector<vector<int> > values) {
	if (values.empty()) {
		return 0;
	}
	int rows = values.size();
	int cols = values[0].size();

	vector<int> maxValues(cols, 0);

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			int left = 0;
			int up = 0;

			if (i > 0) {
				up = maxValues[j]; // 逐行扫描, 这就是当前行上面的一行元素
			}
			if (j > 0) {
				left = maxValues[j - 1];
			}
			maxValues[j] = max(left, up) + values[i][j];
		}
	}
	int maxValue = maxValues[cols - 1];

	return maxValue;
}


// 解法三: 递归解法
// 递归实际上是自下向上的选取最大值
int getMaxValue_solution3_Core(vector<vector<int> >& values,
	int row, int col, int rows, int cols);


int getMaxValue_solution3(vector<vector<int> > values) {
	if (values.empty()) {
		return 0;
	}
	int rows = values.size();
	int cols = values[0].size();

	return getMaxValue_solution3_Core(values, 0, 0, rows, cols);
	
}

int getMaxValue_solution3_Core(vector<vector<int> >& values, 
	                           int row, int col, int rows, int cols) {
	if (values.empty() || row < 0 || col < 0) {
		return 0;
	}

	int result = 0;
	int right = 0;
	int down = 0;
	if (row < (rows - 1)) {
		down = getMaxValue_solution3_Core(values, row + 1, col, rows, cols);
	}

	if (col < (cols - 1)) {
		right = getMaxValue_solution3_Core(values, row, col + 1, rows, cols);
	}

	result = max(down, right) + values[row][col];

	return result;
}
