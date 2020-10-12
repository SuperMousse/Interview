// 循环数组中的最大子数组和
// 情况一：最大子数组仅出现在数组中间 [a, b, c, maxSubarray, d, e], 转化为普通的最大子数组
// 情况二: 最大子数组包含了数组的头部和尾部, [maxSubarray, a, b, c, maxSubarray],
//         头部和尾部最大化等价于数组中部最小化, maxSubarray => min(a+b+c)
//                                                     = totalSum - min(a+b+c)
// 边界条件: 如果所有的数字都是负数, maxSum = max(A), minSum = sum(A)
//          max(maxSum, total-minSum) = 0, 此时需要返回max(A)
int maxSubarraySumCircular(vector<int>& A) {
    int curMax = 0;
    int maxSum = A[0];
    int curMin = 0;
    int minSum = A[0];
    int totalSum = 0;
    for (int num : A) {
        curMax = max(curMax + num, num);
        maxSum = max(maxSum, curMax);
        curMin = min(curMin + num, num);
        minSum = min(minSum, curMin);
        totalSum += num;
    }
    return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
}
