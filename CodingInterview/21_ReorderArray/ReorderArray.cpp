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


// 剑指offer进阶解法，使用函数指针，可以将这个问题泛化，每次传进isEven或者其他函数的指针即可
bool isEven(int n) {
	return (n & 1) == 0;
}

void reOrderArray(vector<int>& array, bool (*func)(int)) {
	if (array.empty())
		return;
	unsigned int start = 0;
	unsigned int end = array.size() - 1;
	while (start < end) {
		while (start < end && !func(array[start]))
			++start;
		while (start < end && func(array[start]))
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
