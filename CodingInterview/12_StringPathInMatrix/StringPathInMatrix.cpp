bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr) {
		return false;
	}
	// visited matrix init
	bool* visited = new bool[rows * cols];
	//memset(visited, 0, rows*cols)
	for (int i = 0; i < rows * cols; ++i) {
		visited[i] = 0;
	}

	int pathLength = 0;
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited)) {
				delete[] visited;
				return true;
			}
		}
	}

	delete[] visited;
	return false;
}



bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, 
		            const char* str, int& pathLength, bool* visited) {
	if (str[pathLength] == '\0') {
		return true;
	}

	bool hasPath = false;
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& matrix[row * cols + col] == str[pathLength]
		&& !visited[row * cols + col]) {
		++pathLength;
		visited[row * cols + col] = true;

		hasPath = hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
				    || hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited)
				    || hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
				    || hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited);

		if (!hasPath) {
			--pathLength;
			visited[row * cols + col] = false;
		}
	}
	return hasPath;
}
