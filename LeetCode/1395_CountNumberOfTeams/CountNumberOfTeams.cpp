// 给定一个数组rating, 找到三个数字i, j, k, 并且
// 满足rating[i] < rating[j] < rating[k] or rating[i] > rating[j] > rating[k], (0 <= i < j < k < n)
// 时间复杂度: O(N^2)

// 假设当前数字为i, 任意一个其他数字为j
// less[0]: rating[i] < rating[j] && j < i, j在i左侧, less[0]表示符合条件的j有多少个
// less[1]: rating[i] < rating[j] && j > i, j在i右侧
// greater[0]: rating[i] > rating[j] && j < i, j在左侧
// greater[1]: rating[i] > rating[j] && j > i, j在右侧
int numTeams(vector<int>& rating) {
    int count = 0;
    int length = rating.size();
    for (int i = 0; i < length - 1; ++i) {
        vector<int> less(2, 0);
        vector<int> greater(2, 0);
        for (int j = 0; j < length; ++j) {
            if (rating[i] < rating[j]) {
                ++less[j > i]; // ++less[j > i ? 1 : 0]
            }
            if (rating[i] > rating[j]) {
                ++greater[j > i];
            }
        }
        // 当前数字左侧比当前数字大的less[0] * 当前数字右侧比当前数字小的greater[1]
        count += less[0] * greater[1] + greater[0] * less[1];
    }
    return count;
}
