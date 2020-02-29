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
