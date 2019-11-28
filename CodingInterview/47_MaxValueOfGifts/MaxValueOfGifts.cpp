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
