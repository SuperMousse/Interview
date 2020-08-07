// 认为从[begin, end]区间内的位置能够跳到当前位置i, fastest是[begin, end]区间内的点能够到达的最远距离
// 一旦当前点跳到了end位置上, 那么一定会发生一次额外的jump, 此时更新jump+=1,

// Input: [1, 2, 2, 1, 4]
// Output: 4

int jump(vector<int>& nums) {
    int farest = 0;
    int end = 0;
    int jumps = 0;
    for (int i = 0; i < nums.size(); ++i) {
        farest = max(farest, i+nums[i]);
        if (i == end) {
            end = farest;
            ++jumps;
        }
    }
    return jumps;
}
