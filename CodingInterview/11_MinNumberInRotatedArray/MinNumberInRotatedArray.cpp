// iterator写法
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


// int作为索引的写法
int minNumberInRotateArray(vector<int> rotateArray) {
	if (rotateArray.empty()) {
		throw runtime_error("Invalid Input");
	}
	unsigned int left = 0;
	unsigned int right = rotateArray.size() - 1;
	unsigned int mid = left;
	while (rotateArray[left] >= rotateArray[right]) {
		if ((right - left) == 1) {
			mid = right;
			break;
		}
		mid = left + (right - left) / 2;

		if (rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid]) {
			return minInOrder(rotateArray, left, right);
		}

		if (rotateArray[mid] >= rotateArray[left]) {
			left = mid;
		}
		else if (rotateArray[mid] <= rotateArray[right]) {
			right = mid;
		}
	}
	return rotateArray[mid];
}

int minInOrder(vector<int>& data, unsigned int start, unsigned int end) {
	int result = data[0];
	for (int i = 0; i <= end; ++i) {
		if (data[i] < result) {
			result = data[i];
		}
	}
	return result;
}
