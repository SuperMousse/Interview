class Solution {
public:
    // 需要找不重复的，且和为0的三元组
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // 数组有重复元素，重复元素跳过；
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int k = nums.size() - 1; // 指针在第二层循环直接放到尾部
            int target = -1 * nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }
                // 需要保证j在k左侧, 才能是<i, j, k>的无重复数组
                while(j < k && nums[j] + nums[k] > target) {
                    --k;
                }
                // 如果指针重合, k增加, 后续不会有a+b+c=0, 且b<c的c了，退出
                if (j == k) {
                    break;
                }
                if (nums[j] + nums[k] == target) {
                    result.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return result;
    }
};
