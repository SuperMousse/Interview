
// 最简单的， 哈希表计数，看是不是大于一半
// 投票法，多数数字记为+1，其他为-1
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for (auto& num: nums) {
            if (count == 0) {
                candidate = num;
            }
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};
