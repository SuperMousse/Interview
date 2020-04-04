Given a non-empty integer array of size n, find the minimum number of moves 
required to make all array elements equal, where a move is incrementing n - 1 
elements by 1.

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]


// 定义sum为数组中所有数字的和, m为变换的次数, n为数字的长度, x为最终变换的结果, minNum为数组中最小的数字
// sum + m * (n - 1) = x * n
// x = minNum + m, 因为数组中最小的数字经过变换后还是最小的, 他变换的次数就是所有数字的变换次数
// 推出 m = sum - n * minNum
