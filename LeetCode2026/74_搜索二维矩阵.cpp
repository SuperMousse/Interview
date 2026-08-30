// 方法一：搜索mxn的矩阵中是否有target，二维矩阵展开成一维矩阵二分搜索
// 方法二：行、列分别进行二分搜索
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int width = matrix[0].size();
        int height = matrix.size();
        int totalSize = width * height;
        int begin = 0;
        int end = totalSize - 1;
        while(begin <= end) {
            int half = begin + (end - begin) / 2;
            int num = matrix[half/width][half%width];
            if (target == num) {
                return true;
            }
            if (target <= num) {
                end = half - 1;
            }
            else {
                begin = half + 1;
            }
        }
        return false;
    }
};
