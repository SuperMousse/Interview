    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        vector<vector<int> > result(n, vector<int>(n, 0));
        int up = 0;
        int down = n - 1;
        int left = 0;
        int right = n - 1;
        while (true) {
            // 最上面一行
            for (int col = left; col <= right; ++col) {
                result[up][col] = num++;
            }
            ++up; // 向下
            // 判断是否越界
            if (up > down) {
                break;
            }
            // 最右边一列
            for (int row = up; row <= down; ++row) {
                result[row][right] = num++;
            }
            --right; //向左
            // 判断是否越界
            if (left > right) {
                break;
            }
            // 最下面一行
            for (int col = right; col >= left; --col) {
                result[down][col] = num++;
            }
            --down; // 向上
            // 判断是否越界
            if (up > down) {
                break;
            }
            // 最左边一行
            for (int row = down; row >= up; row--) {
                result[row][left] = num++;
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
