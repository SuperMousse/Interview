// 给定数组找到i, j, k, 满足0 ≤ i < j < k ≤ n-1, 并且 arr[i] < arr[j] < arr[k], 存在三元组返回true, 否则false
// 令三元组为[minNum, maxNum, curNum]
bool increasingTriplet(vector<int>& nums) {
    int minNum = INT_MAX;
    int maxNum = INT_MAX;
    for (int n : nums) {
        if (n <= minNum) {
            minNum = n; // n < minNum
        }
        else if (n <= maxNum) {
            maxNum = n; // n < maxNum
        }
        else {
            return true; // n > minNum, n > maxNum, 找到一个三元组
        }
    }
    return false;
}
