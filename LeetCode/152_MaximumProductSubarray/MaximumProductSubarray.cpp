// maxProduct表示以当前数字为结束的最大乘积
// minProduct表示以当前数字为结束的最小乘积

int maxProduct(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int maxProduct = nums[0];
    int minProduct = nums[0];
    int maxRes = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if(nums[i] >= 0) {
            // 因为要求是连续子数组, 所以对于一个新的元素要么乘上去,
            // 要么在此处重新开始, 所以maxProcut由*nums[i]与新的nums[i]构成
            maxProduct = max(maxProduct * nums[i], nums[i]);
            minProduct = min(minProduct * nums[i], nums[i]);
        }
        else {
            int temp = maxProduct;
            maxProduct = max(minProduct * nums[i], nums[i]);
            minProduct = min(temp * nums[i], nums[i]);
        }
        maxRes = max(maxRes, maxProduct);
    }
    return maxRes;
}
