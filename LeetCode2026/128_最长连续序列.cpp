class Solution {
public:
    // 时间复杂度为 O(n)，空间复杂度为 O(n)
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 0) {
            return 0;
        }
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = 1;
        }
        int maxLen = 0;
        // 注意这里必须遍历map的pair，保证去重，不然会因为原始数组的重复元素过多，导致复杂度劣化
        for (auto pair : map) {
            // 如果当前序列不包含currentNum - 1，说明currentNum是数组的第一个数字，len = 1
            // 只有不包含currentNum - 1的时候/ currentNum是数字第一个数字的时候才进入搜索
            // pair.fist是会可能下溢的，需要注意
            if (pair.first == INT_MIN || map.find(pair.first - 1) == map.end()) {
                int currentNum = pair.first;
                int len = 1;
                while(map.find(currentNum+1) != map.end()) {
                    currentNum += 1;
                    len += 1;
                }
                maxLen = maxLen > len ? maxLen : len;
            }
        }
        return maxLen;
    }
};
