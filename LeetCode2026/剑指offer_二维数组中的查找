class Solution {
public:
    bool findTargetIn2DPlants(vector<vector<int>>& plants, int target) {
        if(plants.empty()) {
            return false;
        }
        // 每一行递增，每一列递增，但是没有保证前一行的最后一个元素小于后一行的第一个元素
        // 因此对于以下数组，只有从左上角或者右下角搜索才能确定搜索方向，右上角搜索的话，左边数字变小，右边数字变化
        // 但是比如左上角的数字，向右和向下都是变大，就没法搜索了
        /*
        1  4  7
        2  5  8
        3  6  9
        */
        int rows = plants.size();
        int cols = plants[0].size();
        int target_rows = 0;
        int target_cols = cols - 1;
        while (target_rows < rows && target_cols >= 0) {
            if (plants[target_rows][target_cols] == target) {
                return true;
            }
            if (target < plants[target_rows][target_cols]) {
                --target_cols;
            } else {
                ++target_rows;
            }
        }
        return false;
    }
};
