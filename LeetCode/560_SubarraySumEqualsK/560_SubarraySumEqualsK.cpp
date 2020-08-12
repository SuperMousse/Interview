// 给定数组和数字k, 找到连续子数组使得连续子数组之和为k, 返回满足要求的连续子数组中的个数
// 分析: 使用问题的关键是计算[i, j]之间的数字和, 使用hash保存[0, i-1]和[0, j]的和,
// 那么[i, j]的和 = [0, j]的和 - [0, i-1]的和

// sum[i, j] = sum[0, j] - sum[0, i - 1]    --> sum[0, i - 1] = sum[0, j] - sum[i, j]
//     k           sum      hashmap-key     -->  hashmap-key  =  sum - k

int subarraySum(vector<int>& nums, int k) {
    if (nums.empty()) {
        return -1;
    }
    int length = nums.size();
    int count = 0;
    int sum = 0;
    unordered_map<int, int> hash;
    hash[0] = 1;
    for (int i = 0; i < length; ++i) {
        sum += nums[i];
        if (hash.count(sum - k)) {
            count += hash[sum - k];
        }
        ++hash[sum];
    }
    return count;
}


// 解法二： 排序后双指针， 复杂度O(NlogN)
