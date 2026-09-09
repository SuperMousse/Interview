// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。


class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len == 0) {
            return 0;
        }
        vector<int> leftMax(len, 0); // 表示i及其左边位置上最高的位置
        vector<int> rightMax(len, 0); // 表示i及其右面位置上最高的位置
        leftMax[0] = height[0];
        for (int i = 1; i < len; i++) {
            leftMax[i] = leftMax[i-1] > height[i] ? leftMax[i-1] : height[i];
        }
        rightMax[len-1] = height[len-1];
        for (int i = len-2; i >= 0; i--) {
            rightMax[i] = rightMax[i+1] > height[i] ? rightMax[i+1] : height[i];
        }
        int result = 0;
        for (int i = 0; i < len; i++) {
            result += min(leftMax[i], rightMax[i]) - height[i]; // 左右最低的 - 基础高度 = 雨水高度
        }
        return result;
    }
};
