// 含有重复字符的permutation, 在swap之前判断区间内有无重复字符再swap

bool IsSwap(vector<int>& nums, int begin, int end) {
    for (int i = begin; i < end; ++i) {
        if (nums[i] == nums[end]) {
            return false;
        }
    }
    return true;
}

void permuteUniqueCore(vector<int>& nums, vector<vector<int> >& result, int begin) {
    if (begin == nums.size() - 1) {
        result.push_back(nums);
        return;
    }
    for (int i = begin; i < nums.size(); ++i) {
        if (IsSwap(nums, begin, i)) {
            swap(nums[i], nums[begin]);
            permuteUniqueCore(nums, result, begin+1);
            swap(nums[i], nums[begin]);
        }
    }
    return;
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    if (nums.empty()) {
        return vector<vector<int> >();
    }
    vector<int> temp(nums);
    vector<vector<int> > result;
    permuteUniqueCore(nums, result, 0);
    return result;
}
