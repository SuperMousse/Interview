解法一:

// 解法二
// 时间复杂度: O(N^2)
// 空间复杂度: O(1)

int numIdenticalPairs(vector<int>& nums) {
    int len = nums.size();
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] == nums[j]) {
                ++count;
            }
        }
    }
    return count;
}
