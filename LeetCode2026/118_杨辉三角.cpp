class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for (int i = 0; i < numRows; i++) {
            // 第1行1个，第2行2个，...
            result[i].resize(i+1);
            // 初始化最外层的1，包含第一个和最后一个
            result[i][0] = 1;
            result[i][i] = 1;
            // 中间的
            for (int j = 1; j < i; ++j) {
                result[i][j] = result[i-1][j] + result[i-1][j-1];
            }
        }
        return result;
    }
};
