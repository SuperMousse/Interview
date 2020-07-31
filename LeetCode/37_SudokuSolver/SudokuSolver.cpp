void solveSudoku(vector<vector<char>>& board) {
    if (board.empty()) {
        return;
    }
    int rows = board.size();
    int cols = board[0].size();
    solvePuzzle(board, rows, cols);
    return;
}

// 判断row, col位置上能否放置
bool canPlaceNum(vector<vector<char>>& board, int row, int col,
                 char num) {
    for (int i = 0; i < 9; ++i) {
        // 检查同一列的元素
        if (board[i][col] != '.' && board[i][col] == num) {
            return false;
        }
        if (board[row][i] != '.' && board[row][i] == num) {
            return false;
        }
        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] != '.' &&
            board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == num) {
            return false;
        }
    }
    return true;
}

bool solvePuzzle(vector<vector<char>>& board, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; ++c) {
                    if (canPlaceNum(board, i, j, c)) {
                        board[i][j] = c;
                        if (solvePuzzle(board, rows, cols)) {
                            return true;
                        }
                        else {
                            board[i][j] = '.';
                        }
                    }

                }
                // i, j 位置上尝试所有的数字失败
                return false;
            }
        }
    }
    // 没有'.'了, 填充完毕
    return true;
}
