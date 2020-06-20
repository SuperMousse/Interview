// 第一次遍历将数组的第0行和第0列置为0, 然后第二次遍历的时候检查第0行或者第0列元素是否为0
// 如果是的话就把当前元素置0
// 但是存在问题就是如果第0行或者第0列的元素本来就是0, 那么会在第二次遍历时导致0传播到不应该为0的位置上
// 所以两次遍历都在第1行第一列以后的位置上进行, 这样0就不会传播
// 但是需要单独将第0行和第0列进行置0
void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool zeroRow = false;
    bool zeroCol = false;
    // 检查第0行和第0列是否有0
    for (int i = 0; i < rows; ++i) {
        if (matrix[i][0] == 0) {
            zeroCol = true;
        }
    }
    for (int j = 0; j < cols; ++j) {
        if (matrix[0][j] == 0) {
            zeroRow = true;
        }
    }
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    // 将第0行和第0列置0
    if (zeroCol) {
        for (int i = 0; i < rows; ++i) {
            matrix[i][0] = 0;
        }
    }
    if (zeroRow) {
        for (int j = 0; j < cols; ++j) {
            matrix[0][j] = 0;
        }
    }
    return;
}
