// 剑指offer答案
void reOrderArray(vector<int>& array) {
	if (array.empty())
		return;
	unsigned int start = 0;
	unsigned int end = array.size() - 1;
	while (start < end) {
		while (start < end && (array[start] % 2) != 0)
			++start;
		while (start < end && (array[end] % 2) == 0)
			--end;
		if (start < end) {
			int temp = array[start];
			array[start] = array[end];
			array[end] = temp;
		}

	}
}

// 牛客网上还要求交换后奇数与奇数，偶数与偶数的相对位置不变
void reOrderArray(vector<int>& array) {
	stable_partition(array.begin(), array.end(), isOk); // stable partition根据谓词把序列分成两个子列，并且保持原有的序列顺序
}


bool isOk(int n) {
	return ((n & 1) == 1);　//奇数返回真
}

// lamda解法
void reOrderArray(vector<int>& array) {
	stable_partition(array.begin(), array.end(), [](int n) {return ((n & 1) == 1); }); // stable partition根据谓词把序列分成两个子列，并且保持原有的序列顺序
}
