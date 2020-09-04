// 解法一: 一次二分完成查找

int search(vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int len = nums.size();
    int left = 0;
    int right = len - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] == target) {
            return middle;
        }
        if (nums[middle] >= nums[left]) {
            if (target >= nums[left] && target < nums[middle]) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }
        else {
            if (target > nums[middle] && target <= nums[right]) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
    }
    return -1;
}
 

 // 解法二: 两次二分搜索
 // 先找到最小元素，然后再进行正常的二分搜索
 int search(vector<int>& nums, int target) {
   if (nums.empty()) {
     return -1;
   }
   int minIndex = findMinIndex(nums);
   if (target == nums[minIndex]) {
     return minIndex;
   }		 
   int length = nums.size();
   int start = (target <= nums[length - 1]) ? minIndex : 0;
   int end = (target <= nums[length - 1]) ? length - 1: minIndex;
   while (start <= end) {
     int middle = (start + end) / 2;
     if (nums[middle] == target) {
       return middle;
     }
     else if (target > nums[middle]) {
       start = middle + 1;
     }
     else {
       end = middle - 1;
     }
   }
   return -1;
 }

// findMinIndex的leetcode解法
   int findMinIndex(vector<int>& nums) {
       int start = 0;
       int end = nums.size() - 1;
       while (start < end) {
           int middle = (start + end) / 2;
           if (nums[middle] > nums[end]) {
               start = middle + 1;
           }
           else {
               end = middle;
           }
       }
       return start;
   }

// findMinIndex的剑指offer解法
 int findMinIndex(vector<int>& nums) {
	 int start = 0;
	 int end = nums.size() - 1;
	 int middle = 0;
	 while (nums[start] > nums[end]) {
		 if ((end - start) == 1) {
			 middle = end;
			 break;
		 }
		 int middle = (start + end) / 2;
		 if (nums[middle] > nums[end]) {
			 start = middle;
		 }
		 else {
			 end = middle;
		 }
	 }
	 return middle;
 }





