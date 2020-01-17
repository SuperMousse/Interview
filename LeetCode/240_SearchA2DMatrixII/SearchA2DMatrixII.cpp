bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) {
        return false;
    }
    int rows = matrix.size();
    int cols = matrix[0].size();
    int row = 0;
    int col = cols - 1;
    while (row >= 0 && row < rows && col >= 0 && col < cols) {
        if(target == matrix[row][col]) {
            return true;
        }
        else {
            if(target < matrix[row][col]) {
                --col;
            }
            else{
                ++row;
            }
        }

    }

    return false;
}
