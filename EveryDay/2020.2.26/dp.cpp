
// 最大连续乘积子数组
// maxProduct = max(nums[i]*maxProduct, nums[i])
// 需要注意这里, 因为要求是连续子数组, 所以一个数字在新的位置上要么乘上去, 要么重新开始
int maxProduct(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int maxProduct = nums[0];
    int minProduct = nums[0];
    int maxRes = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if(nums[i] > 0) {
            maxProduct = max(nums[i]*maxProduct, nums[i]);
            minProduct = min(nums[i]*minProduct, nums[i]);
        }
        else {
            int temp = maxProduct;
            maxProduct = max(nums[i]*minProduct, nums[i]);
            minProduct = min(nums[i]*temp, nums[i]);
        }
        maxRes = max(maxRes, maxProduct);
    }
    return maxRes;
}

