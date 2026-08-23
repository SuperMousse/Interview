class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            maxArea = max(area, maxArea);
            // 水桶越来越窄, 因此只能把短板换成更高的板, 才能增加面积
            if (height[left] <= height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxArea;
    }
};
