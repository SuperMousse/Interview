vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    if (mat.empty()) {
        return mat;
    }
    int rows = mat.size();
    int cols = mat[0].size();
    vector<vector<int> > res(rows, vector<int>(cols, 0));
    unordered_map<int, vector<int> > hash;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            hash[i-j].push_back(mat[i][j]);
        }
    }

    for(int k= -(cols - 1); k < rows ; ++k) {
        sort(hash[k].begin(), hash[k].end(), greater<int>());
    }
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            res[i][j] = hash[i-j].back();
            hash[i-j].pop_back();
        }
    }
    return res;
}
