// 贪心算法
// 时间复杂度O(N)
// 从前向后考虑每个元素, 当前所能到达的最远距离是max(当前位置+当前元素, 最大距离)

bool canJump(vector<int>& nums) {
    if(nums.empty()){
        return false;
    }
    int maxIndex = nums.size();
    int farest = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if(farest < i) {
            return false;
        }
        farest = max(i + nums[i], farest);
    }

    return true;
}

// 解法二: 贪心算法从后向前
// 从后向前扫描, 每次保留最后一个当前能够跳到最后一个元素的位置
bool canJump(vector<int>& nums) {
    if(nums.empty()){
        return false;
    }
    int length = nums.size();
    int lastIndex = length - 1;
    for (int i = length - 2; i >= 0; --i) {
        if((i + nums[i]) >= lastIndex) {
            lastIndex = i;
        }
    }
    return lastIndex <= 0;
}
