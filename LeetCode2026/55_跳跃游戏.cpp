class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxLen = 0;
        int len = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            // 只有i <= maxLen的时候，说明位置i是靠maxLen逐步能跳过来的，不然就是跳不过来的
            if (i <= maxLen) {
                int currMaxLen = i + nums[i]; // 当前i往后最多跳nums[i]步
                maxLen = currMaxLen > maxLen ? currMaxLen : maxLen;
                if (maxLen >= len-1) {
                    return true;
                }
            }
        }
        return false;
    }
};
