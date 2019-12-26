void rotate(vector<vector<int>>& matrix) {
    if(matrix.empty()){
        return;
    }
    reverse(matrix.begin(), matrix.end());
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = i; j < cols; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    return;
}
