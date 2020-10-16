// 方法一： 时间复杂度O(kN), 采用循环进行多次比较
int nthSuperUglyNumber(int n, vector<int>& primes) {
    if (n < 0 || n > 1000000 || primes.size() > 100) {
        return 0;
    }
    int k = primes.size();
    vector<int> dp(n, 0);
    vector<int> lastIndex(k, 0);
    dp[0] = 1;

    for (int nextUglyIndex = 1; nextUglyIndex < n; ++nextUglyIndex) {
        int minNum = INT_MAX;
        for (int i = 0; i < k; ++i) {
            minNum = min(minNum, dp[lastIndex[i]] * primes[i]);
        }
        dp[nextUglyIndex] = minNum;
        for (int i = 0; i < k; ++i) {
            if(dp[lastIndex[i]] * primes[i] == dp[nextUglyIndex]) {
                ++lastIndex[i];
            }
        }
    }
    return dp[n - 1];
}

// 方法二: 时间复杂度O(log(k)N), 采用最小堆进行大小比较
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n < 0 || n > 1000000 || primes.size() > 100) {
            return 0;
        }
        int k = primes.size();
        vector<int> dp(n, 0);
        dp[0] = 1;

        vector<number> heap;
        for (int i = 0; i < k; ++i) {
            number temp(i, 0, primes[i]);
            heap.push_back(temp);
        }
        make_heap(heap.begin(), heap.end(), cmp);

        for (int nextUglyIndex = 1; nextUglyIndex < n; ++nextUglyIndex) {
            number n = heap[0];
            int minNum = n.val;
            if (minNum == dp[nextUglyIndex - 1]) {
                --nextUglyIndex; // 如果有重复元素, 此次写入不计算在内
            }
            dp[nextUglyIndex] = minNum;

            pop_heap(heap.begin(), heap.end(), cmp);
            heap.pop_back();
            ++n.lastIndex;
            n.val = dp[n.lastIndex] * primes[n.arrayIndex];
            heap.push_back(n);
            push_heap(heap.begin(), heap.end(), cmp);

        }
        return dp[n - 1];
    }

private:
    struct number {
        int arrayIndex = 0;
        int lastIndex = 0;
        int val = 0;
        number(int a, int l, int v) : arrayIndex(a), lastIndex(l), val(v) {}
    };

    bool cmp(number& a, number& b) {
        return a.val > b.val;     // 大于定义小顶堆

    }
};
