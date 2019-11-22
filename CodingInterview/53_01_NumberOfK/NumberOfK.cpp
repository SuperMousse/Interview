// 直观解法一, 顺序扫描, 时间复杂度O(N)
int GetNumberOfK(vector<int> data, int k) {
	if (data.empty()) {
		return 0;
	}
	int numbers = 0;
	for (int i = 0; i < data.size(); ++i) {
		if (data[i] == k)
			++numbers;
	}
	return numbers;
}


// 解法二, 二分查找+左右扫描, 由于顺序扫描时间复杂度为时间复杂度O(N), 则该算法最差时间复杂度为O(N)


// 解法三, 二分查找first value+二分查找last value, 时间复杂度O(logN)
// (一)递归二分查找 
int GetNumberOfK(vector<int> data, int k) {
	if (data.empty()) {
		return 0;
	}
	int numbers = 0;
	int first = GetFirstK(data, k, 0, data.size() - 1);
	int last = GetLastK(data, k, 0, data.size() - 1);

	if (first >= 0 && last >= 0) {
		numbers = last - first + 1;
	}
	return numbers;
}

int GetFirstK(vector<int>&data, int k, int start, int end) {
	if (start > end) {
		return -1;
	}
	int middle = (start + end) / 2;
	if (data[middle] == k) {
		if ((middle > 0 && data[middle - 1] != k) || middle == 0) {
			return middle;
		}
		else {
			end = middle - 1;
		}
	}
	else if (data[middle] < k) {
		start = middle + 1;
	}
	else {
		end = middle - 1;
	}
	return GetFirstK(data, k, start, end);
}

int GetLastK(vector<int>& data, int k, int start, int end) {
	if (start > end) {
		return -1;
	}
	int middle = (start + end) / 2;
	if (data[middle] == k) {
		if ((middle < data.size() - 1 && data[middle + 1] != k) || middle == data.size() - 1) {
			return middle;
		}
		else {
			start = middle + 1;
		}
	}
	else if (data[middle] < k) {
		start = middle + 1;
	}
	else {
		end = middle - 1;
	}
	return GetLastK(data, k, start, end);
}


// (二) 非递归二分查找

int GetNumberOfK(vector<int> data, int k) {
	if (data.empty()) {
		return 0;
	}

	int numbers = 0;
	int first = GetFirstK(data, k);
	int last = GetLastK(data, k);
	if (first >= 0&& last >= 0) {
		numbers = last - first + 1;
	}
	return numbers;
}


int GetFirstK(vector<int>& data, int k) {
	if (data.empty()) {
		return -1;
	}
	int length = data.size();
	int start = 0;
	int end = length - 1;
	int middle = (start + end) / 2;
	while (start <= end) {
		if (data[middle] == k) {
			if ((middle > 0 && data[middle - 1] != k) || middle == 0) {
				return middle;
			}
			else {
				end = middle - 1;
			}
		}
		else {
			if (data[middle] < k) {
				start = middle + 1;
			}
			else {
				end = middle - 1;
			}
		}
		middle = (start + end) / 2;
	}
	return -1;
}


int GetLastK(vector<int>& data, int k) {
	if (data.empty()) {
		return -1;
	}
	int length = data.size();
	int start = 0;
	int end = length - 1;
	int middle = (start + end) / 2;
	while (start <= end) {
		if (data[middle] == k) {
			if ((middle < length - 1 && data[middle + 1] != k) || middle == length - 1) {
				return middle;
			}
			else {
				start = middle + 1;
			}
		}
		else {
			if (data[middle] < k) {
				start = middle + 1;
			}
			else {
				end = middle - 1;
			}
		}
		middle = (start + end) / 2;
	}
	return -1;
}
