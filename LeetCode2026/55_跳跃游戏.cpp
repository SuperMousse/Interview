/*
给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
*/
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
