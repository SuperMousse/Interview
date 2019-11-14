// fowllow剑指offer解法, vector空间控制存在问题，待修改
// 线下结果正常，但是牛客网无法正常通过，空间不足
vector<int> printMatrix(vector<vector<int> > matrix) {
	unsigned int rows = matrix.size();
	unsigned int columns = matrix[0].size();
	vector<int> result;
	if (rows <= 0 || columns <= 0) {
		return result;
	}
	unsigned int start = 0;
	while ((rows > start * 2) && (columns > start * 2)) {
		vector<int> temp = printMatrixInCircle(matrix, rows, columns, start);
		result.insert(result.end(), temp.begin(), temp.end());
		++start;
	}
	return result;
}


vector<int> printMatrixInCircle(vector<vector<int> > matrix, unsigned int rows, 
                                unsigned int columns, unsigned int start) {
	vector<int> result;
	unsigned int endX = columns - 1 - start;
	unsigned int endY = rows - 1 - start;
	// 从左到右打印一行
	for (unsigned int i = start; i <= endX; ++i) {
		int number = matrix[start][i];
		result.push_back(number);
	}


	// 从上到下打印一列
	if (start < endY) {
		for (unsigned int i = start + 1; i <= endY; ++i) {
			int number = matrix[i][endX];
			result.push_back(number);
		}
	}

	// 从右到左打印一行
	if (start < endX && start < endY) {
		for (unsigned int i = endX - 1; ; --i) {
			int number = matrix[endY][i];
			result.push_back(number);
			if (i == start) // i=0时i-1 unsigned int下溢
				break;
		}
	}

	// 从下到上打印一列
	if (start < endX && start < endY - 1) {
		for (unsigned int i = endY - 1; i>=start+1; --i) {
			int number = matrix[i][start];
			result.push_back(number);
		}
	}
	return result;
}



// 牛客网上的解法，使用4个label标记
vector<int> printMatrix(vector<vector<int> > matrix) {
	int rows = (int)matrix.size();
	int columns = (int)matrix[0].size();
	vector<int> result;
	if (matrix.empty() || rows == 0 || columns == 0) {
		return result;
	}
	int up = 0;
	int down = rows - 1;
	int left = 0;
	int right = columns - 1;
	while (true) {
		// 最上面一行
		for (int col = left; col <= right; ++col) {
			result.push_back(matrix[up][col]);
		}
		++up; // 向下
		// 判断是否越界
		if (up > down) {
			break;
		}
		// 最右边一列
		for (int row = up; row <= down; ++row) {
			result.push_back(matrix[row][right]);
		}
		--right; //向左
		// 判断是否越界
		if (left > right) {
			break;
		}
		// 最下面一行
		for (int col = right; col >= left; --col) {
			result.push_back(matrix[down][col]);
		}
		--down; // 向上
		// 判断是否越界
		if (up > down) {
			break;
		}
		// 最左边一行
		for (int row = down; row >= up; row--) {
			result.push_back(matrix[row][left]);
		}
		// 向右
		++left;
		// 判断是否越界
		if (left > right) {
			break;
		}

	}
	return result;
}
