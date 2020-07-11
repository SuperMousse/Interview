// 将数组 A, B分成左右两部分:  
// A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1], A的前i个元素  
// B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]， B的前j个元素  
// 1) len(left_part) == len(right_part)  =>  i + j == m - i + n - j (或者: m - i + n - j + 1)  => when n > m, i = 0 ~ m, j = (m + n + 1)/2 - i  
// (兼容 m + n = 5或者4， 因为整型(5+1)/2=3, 4/2=2, 都是正确答案)
// 2) max(left_part) <= min(right_part)  =>  B[j-1] <= A[i] 并且 A[i-1] <= B[j]  
// 则median = (max(left_part) + min(right_part))/2  


