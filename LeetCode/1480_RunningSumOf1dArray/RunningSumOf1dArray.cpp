// input:  [1, 2, 3, 4]
// output: [1, 3, 6, 10]
// nums[i]等于之前所有的数字之和

vector<int> runningSum(vector<int>& nums) {
    int len = nums.size();
    vector<int> res(len, 0);
    res[0] = nums[0];
    for (int i = 1; i < len; ++i) {
        res[i] = nums[i] + res[i-1];
    }
    return res;
}
