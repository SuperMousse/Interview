//  双指针
int maxArea(vector<int>& height) {
	int maxArea = 0;
	int left = 0;
	int right = height.size() - 1;


	while (left < right) {
		maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
		if (height[left] < height[right]) {
			++left; // 此时如果移动较大的一个，那么板子的高度没变，宽度变小了
		}
		else {
			--right;
		}

		cout << left << " " << right << maxArea << endl;

	}

	return maxArea;
}

