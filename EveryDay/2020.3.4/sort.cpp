// 


// Minimum adjacent swaps to move maximum and minimum to corners
// Given N number of elements, find the minimum number of swaps 
// required so that the maximum element is at the beginning and the 
// minimum element is at last with the condition that only swapping 
// of adjacent elements is allowed.
// 找到左数最大的数字索引l, 右数最小的数字索引r
// If l < r: Number of swaps = l + (n-r-1)
// If l > r: Number of swaps = l + (n-r-2)
