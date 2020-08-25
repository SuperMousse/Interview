// 给定一个数组, 找到两个不同的索引 i, j, nums[i]和nums[j]的绝对值之差最多为t, i和j的绝对值之差最多为k
// 分析: 假设我们有连续的桶覆盖了所有的数字, 其中每个桶覆盖了 (t+1)的宽度, 那么如果两个数字的差 <=t,
//      那么这两个元素 (1)在相同的桶中 (2)在相邻的桶中

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.empty() || t < 0 || k < 0) {
            return false;
        }
        int len = nums.size();
        unordered_map<long long , long long> hash;
        long long window = (long long)t + 1;
        for (int i = 0; i < len; ++i) {
            long long m = getID(nums[i], window); // 桶的编号
            // 如果两个数字在一个桶中, 数字差 <=t, 并且之前已经把 i>=k, 即索引和当前相差超过k的桶去掉
            // 现有的所有桶都是 i - j <= k的
            if (hash.count(m) != 0) {
                return true;
            }
            if (hash.count(m - 1) != 0 && abs(nums[i] - hash[m - 1]) < window) {
                return true;
            }
            if (hash.count(m + 1) != 0 && abs(nums[i] - hash[m + 1]) < window) {
                return true;
            }
            hash[m] = (long long)nums[i];
            // 如果当前元素索引 i>=k, 移除距离当前超过k的桶
            if (i >= k) {
                hash.erase(getID(nums[i-k], window));
            }
        }
        return false;
    }

    long long getID(long long i, long long window) {
        // 如果window=2, -1/2=0(向零取证), 但是应该让-1/2=-1
        // nums:  -2, -1, 0, 1, 2, 3, 4
        // bucket:-1, -1, 0, 0, 1, 1, 2
        return i < 0 ? ((i + 1) / window - 1) : (i / window);
    }
};
