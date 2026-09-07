/*
给定一个长度为 n 的 0 索引整数数组 nums。初始位置在下标 0。

每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在索引 i 处，你可以跳转到任意 (i + j) 处：

0 <= j <= nums[i] 且
i + j < n
返回到达 n - 1 的最小跳跃次数。测试用例保证可以到达 n - 1。
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxLen = 0;
        int len = nums.size();
        int step = 0;
        int beforeMaxLen = 0; // 某一步之前所能达到的最远位置
        // i < len-1是因为最后一个元素必须是提前到达的，不能再往后跳了
        for (int i = 0; i < len-1; i++) {
            int currLen = i + nums[i];
            maxLen = currLen > maxLen ? currLen : maxLen;
            if (i == beforeMaxLen) {
                beforeMaxLen = maxLen; // i 和end相等时说明i的位置上之前最远只能跳到这里了，必须夺走一步了
                step++;
            }
        }
        return step;
    }
};
