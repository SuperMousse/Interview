class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 给定数组和数字k，找到连续子数组使得子数组之和为k，返回满足要求的连续子数组中的个数
        // 关键问题为计算[i, j]的数字和，hash map保存[0，j]的和，map[x]=y，表示前缀和为x的子数组出现了y次
        // 则[i，j]的和 = [0，j]的和 - [0，i-1]的和
        // sum[i, j] = sum[0, j] - sum[0, i-1]
        // k         =  sum - hash_key -> hash_key = sum - k
        if (nums.empty()) {
            return -1;
        }
        int length = nums.size();
        int result = 0; // count
        int sum = 0; // 统计到i位置的前缀和
        unordered_map<int, int> sumMap;
        sumMap[0] = 1;
        for(int i = 0; i < length; i++) {
            sum += nums[i];
            // 查找历史前缀是否出现过 sum - k，如果出现过就说明有k的子数组了
            if (sumMap.find(sum - k) != sumMap.end()) {
                result += sumMap[sum - k];
            }
            sumMap[sum] += 1;
        }
        return result;
    }
};
