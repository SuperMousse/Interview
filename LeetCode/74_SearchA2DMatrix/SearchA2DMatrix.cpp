
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) {
        return false;
    }
    int rows = matrix.size();
    int cols = matrix[0].size();
    int i = 0;
    int j = cols - 1;
    while (i >= 0 && i < rows && j >= 0 && j < cols) {
        if (target == matrix[i][j]) {
            return true;
        }
        else if (target > matrix[i][j]) {
            ++i;
        }
        else {
            --j;
        }
    }
    return false;
}
