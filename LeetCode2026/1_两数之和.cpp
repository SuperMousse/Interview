class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsToIndex;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            int val = target - nums[i];
            if (numsToIndex.find(val) != numsToIndex.end()) {
                result.push_back(numsToIndex[val]);
                result.push_back(i);
                return result;
            }
            numsToIndex[nums[i]] = i;
        }
        return result;
    }
};
