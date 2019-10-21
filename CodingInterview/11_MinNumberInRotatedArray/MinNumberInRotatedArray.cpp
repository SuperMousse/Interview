int minNumberInRotateArray(vector<int> rotateArray) {
	if (rotateArray.empty()) {
		throw runtime_error("Invalid Input");
	}
	vector<int>::iterator left = rotateArray.begin();
	vector<int>::iterator right = rotateArray.end() - 1;
	vector<int>::iterator mid = left;
	while (*left >= *right) {
		if ((right - left) == 1) {
			mid = right;
			break;
		}
		vector<int>::iterator mid = left + (right - left) / 2;

		// 如果left, right, mid指向的数字相等, 则只能顺序查找
		if (*left == *right && *left == *mid) {
			return minInOrder(rotateArray, left, right);
		}
		if (*mid >= *left) {
			left = mid;
		}
		if (*mid <= *right) {
			right = mid;
		}
	}
	return *mid;
}

int minInOrder(vector<int>& data, vector<int>::iterator start, vector<int>::iterator end) {
	int result = *start;
	for (vector<int>::iterator i = start; i <= end; ++i) {
		if (*i < result) {
			result = *i;
		}
	}
	return result;
}
