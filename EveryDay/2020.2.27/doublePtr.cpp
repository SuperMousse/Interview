// 三数之和
        vector<vector<int>> threeSum(vector<int>& nums) {
            if (nums.empty()) {
                return vector<vector<int> >();
            }
            sort(nums.begin(), nums.end(), less<int>()); // 从小到大
            vector<vector<int> > result;
            int length = nums.size();
            // 以nums[i]为锚点, 进行两数之和的计算
            for (int i = 0; i < length - 2; ++i) {
                // 三元组第一个若大于0, 则不可能最后结果为0
                if(nums[i] > 0) {
                    break;
                }
                // 跳过重复元素, 并且多个重复元素里使用第一个, 是因为后面的元素可以重复使用
                // 如果只是使用最后一个的话那前面重复的元素都无法使用了
                if (i==0 || nums[i] != nums[i - 1]) {
                    int left = i + 1;
                    int right = length - 1;
                    int target = -nums[i];
                    while (left < right) {
                        if (nums[left] + nums[right] == target) {
                            result.push_back({nums[i], nums[left], nums[right]});
                            // skip duplicate number
                            while (left < right && nums[left] == nums[left + 1]) {
                                ++left;
                            }
                            while (left < right && nums[right] == nums[right - 1]) {
                                --right;
                            }
                            ++left;
                            --right;
                        }
                        else if(nums[left] + nums[right] < target) {
                            ++left;
                        }
                        else {
                            --right;
                        }
                    }
                }

            }
            return result;
        }



// 无重复字符的最长子串
// 使用hash表, 也可以使用队列进行滑动窗口, 进入一个新的元素时将队首元素出队列
int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
        return 0;
    }
    vector<int> dp(256, -1);
    int maxLength = 0;
    int curLength = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (dp[s[i]] == -1 || (i - dp[int(s[i])] > curLength)) {
            ++curLength;
        }
        else {
            curLength = i - dp[int(s[i])];
        }
        dp[int(s[i])] = i;
        maxLength = maxLength > curLength ? maxLength : curLength;
    }
    return maxLength;
}
