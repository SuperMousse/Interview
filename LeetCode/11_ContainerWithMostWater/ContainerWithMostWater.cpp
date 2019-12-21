//  双指针
int maxArea(vector<int>& height) {
		 int maxArea = 0;
		 int left = 0;
		 int right = height.size() - 1;
		 while (left < right) {
			 maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
			 if (height[left] < height[right]) {
				 ++left;
			 }
			 else {
				 --right;
			 }
		 }
		 return maxArea;
	 }
