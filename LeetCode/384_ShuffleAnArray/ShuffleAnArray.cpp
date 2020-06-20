// 元素打乱
// 遍历[0, length-1]为i, 每次生成一个[0, i]的随机数j， 交换i, j
class Solution {
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if (nums.empty()) {
            return nums;
        }
        vector<int> res(nums.begin(), nums.end());
        for (int i = 1; i < res.size(); ++i) {
            int j = (rand() % (i + 1));
            swap(res[i], res[j]);
        }
        return res;
    }
private:
    vector<int> nums;
    vector<int> random;
};
