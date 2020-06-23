// hash中的键表示数组中的元素, 值表示其最长连续序列的长度
int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    unordered_map<int, int> hash;
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (hash.count(nums[i]) == 0) {
            int left = hash.count(nums[i] - 1) ? hash[nums[i] - 1] : 0;
            int right = hash.count(nums[i] + 1) ? hash[nums[i] + 1] : 0;
            // nums[i]的连续序列长度为其左右元素的长度+1(加自身)
            int sum = left + right + 1;
            // cout << left << " " << right << " " << nums[i] << " " << sum << endl;
            hash[nums[i]] = sum;

            res = res > sum ? res : sum;
            // left/right=0时此句无影响, 不等于0时把和当前数字连接的左和最右的数字也进行更新
            // 这样才能把范围内的数字都设为最大的连续长度, 反例[1, 2, 0, 1]
            hash[nums[i] - left] = sum;
            hash[nums[i] + right] = sum;

        }
        else {
            continue;
        }
    }

    return res;
}
