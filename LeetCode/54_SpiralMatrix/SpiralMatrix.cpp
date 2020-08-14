vector<int> spiralOrder(vector<vector<int> > matrix) {
    if (matrix.empty()) {
        return vector<int>();
    }
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
