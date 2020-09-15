int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int N = grid.size();
    vector<int> rowMaxVal(N, 0);
    vector<int> colMaxVal(N, 0);
    // 用两个N维矩阵分别存储行和列的最大值
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            rowMaxVal[i] = max(rowMaxVal[i], grid[i][j]);
            colMaxVal[j] = max(colMaxVal[j], grid[i][j]);
        }
    }
    // 计算所有建筑能够增加的最大和
    int result = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // 最大高度取决于对应行、列最大值中较小的, 因为不能超过所在行、列的最大值
            result += min(rowMaxVal[i], colMaxVal[j]) - grid[i][j];
        }
    }
    return result;
}
