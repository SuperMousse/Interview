// 八皇后

int totalNQueens(int n) {
    if (n < 1) {
        return 0;
    }
    int count = 0;
    int position = 0;
    vector<int> queen(n, -1);
    findQueen(queen, count, position, n);
    return count;
}


bool canPlaceQueen(vector<int>& queen, int position) {
    for (int i = 0; i < position; ++i) {
        // 皇后不能放在同一列或者斜线上
        if (queen[i] == queen[position] ||
            abs(position - i) == abs(queen[position] - queen[i]) ) {
            return false;
        }
    }
    return true;
}

void findQueen(vector<int>& queen, int& count, int position, int n) {
    if (position == n) {
        ++count;
        return;
    }
    for (int col = 0; col < n; ++col) {
        queen[position] = col;
        if(canPlaceQueen(queen, position)) {
            findQueen(queen, count, position + 1, n);
        }
    }
    return;
}

// 解数独
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

