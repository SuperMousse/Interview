// 将数组 A, B分成左右两部分:  
// A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1], A的前i个元素  
// B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]， B的前j个元素  
// 1) len(left_part) == len(right_part)  =>  i + j == m - i + n - j (或者: m - i + n - j + 1)  => when n > m, i = 0 ~ m, j = (m + n + 1)/2 - i  
// (兼容 m + n = 5或者4， 因为整型(5+1)/2=3, 4/2=2, 都是正确答案)
// 2) max(left_part) <= min(right_part)  =>  B[j-1] <= A[i] 并且 A[i-1] <= B[j]  
// 则median = (max(left_part) + min(right_part))/2  


// 在搜索循环中，我们只会遇到三种情况：  

// <a> (j == 0 or i == m or B[j-1] <= A[i]) and  
//     (i == 0 or j = n or A[i-1] <= B[j])  
//     说明 i 的值满足要求，停止循环  

// <b> j > 0 and i < m and B[j - 1] > A[i]  
//     说明 i 的值太小， 增加它  

// <c> i > 0 and j < n and A[i - 1] > B[j]  
//     说明 i 的值过大， 减小它  


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
            if (i == 0) { // i == 0 || j == 0需要停止
                maxOfLeft = nums2[j-1];
            }
            else if (j == 0) {
                maxOfLeft = nums1[i-1];
            }
            else {  // i, j均不为0， 满足 B[j-1] <= A[i] && A[i-1] <= B[j]
                maxOfLeft = max(nums1[i-1], nums2[j-1]);
            }
            if ((m + n) % 2 == 1) {
                return maxOfLeft;
            }

            if (i == m) {  // i == m || j == n需要停止
                minOfRight = nums2[j];
            }
            else if (j == n) {
                minOfRight = nums1[i];
            }
            else { // i != m, j != n, 满足 B[j-1] <= A[i] && A[i-1] <= B[j]
                minOfRight = min(nums1[i], nums2[j]);
            }
            return (maxOfLeft + minOfRight) / 2.0;
        }
    }
    return -1;
}
