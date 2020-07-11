// 将数组 A, B分成左右两部分:  
// A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1], A的前i个元素  
// B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]， B的前j个元素  
// 1) len(left_part) == len(right_part)  =>  i + j == m - i + n - j (或者: m - i + n - j + 1)  => when n > m, i = 0 ~ m, j = (m + n + 1)/2 - i  
// (兼容 m + n = 5或者4， 因为整型(5+1)/2=3, 4/2=2, 都是正确答案)
// 2) max(left_part) <= min(right_part)  =>  B[j-1] <= A[i] 并且 A[i-1] <= B[j]  
// 则median = (max(left_part) + min(right_part))/2  


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if (n < m) {
        return findMedianSortedArrays(nums2, nums1);
    }
    int imin = 0;
    int imax = m;
    int i = 0;
    int j = 0;
    int halfTotalLen = (m + n + 1) / 2;
    while (imin <= imax) {
        i = (imin + imax) / 2;
        j = halfTotalLen - i;
        // i, j不在边界值并且需要继续迭代
        if (i > 0 && j < n && nums1[i-1] > nums2[j]) {
            imax = i - 1;
        }
        else if (j > 0 && i < m && nums2[j-1] > nums1[i]) {
            imin = i + 1;
        }
        // i,j 到达可能停止的位置
        else {
            int maxOfLeft = 0;
            int minOfRight = 0;
            if (i == 0) {
                maxOfLeft = nums2[j-1];
            }
            else if (j == 0) {
                maxOfLeft = nums1[i-1];
            }
            else {
                maxOfLeft = max(nums1[i-1], nums2[j-1]);
            }
            if ((m + n) % 2 == 1) {
                return maxOfLeft;
            }

            if (i == m) {
                minOfRight = nums2[j];
            }
            else if (j == n) {
                minOfRight = nums1[i];
            }
            else {
                minOfRight = min(nums1[i], nums2[j]);
            }
            return (maxOfLeft + minOfRight) / 2.0;
        }
    }
    return -1;
}
