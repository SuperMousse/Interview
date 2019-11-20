// 第一反应的解法, 哈希表, 空间复杂度O(N)

int MoreThanHalfNum_Solution(vector<int> numbers) {
	if (numbers.empty()) {
		return 0;
	}
	unordered_map<int, int> frequency;
	int length = numbers.size();
	for (int i = 0; i < length; ++i)
	{
		auto result = frequency.insert(pair<int, int>(numbers[i], 1));
		if (!result.second) {
			++(result.first->second);
		}
	}

	for (auto key_value : frequency) {
		if (key_value.second > (length / 2)) {
			return key_value.first;
		}
	}

	return 0;
}


// 剑指offer解法, 两种空间复杂度O(1)的解法
// 解法一, 利用quick sort的partition函数来查找中位数
int MoreThanHalfNum_Solution(vector<int> numbers) {
	if (numbers.empty()) {
		return 0;
	}
	int length = numbers.size();
	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(numbers, start, end);
	while (index != middle) {
		if (index > middle) {
			end = index - 1;
			index = Partition(numbers, start, end);
		}
		else {
			start = index + 1;
			index = Partition(numbers, start, end);
		}
	}

	int result = numbers[middle];
	// 确认result次数是否真的超过了n/2
	if (!CheckMoreThanHalf(numbers, result)) {
		return 0;
	}

	return result;
}

bool CheckMoreThanHalf(vector<int>& numbers, int result) {
	if (numbers.empty()) {
		return false;
	}
	int times = 0;
	for (int i = 0; i < numbers.size(); ++i){
		if (numbers[i] == result) {
			++times;
		}
	}

	bool isMoreThanHalf = true;
	if (times * 2 <= numbers.size()) {
		return false;
	}
	return isMoreThanHalf;
}


int Partition(vector<int>& numbers, int start, int end) {
	if (numbers.empty()) {
		return 0;
	}
	int base = start;
	int left = start;
	int right = end;
	while (true) {
		while (left<right && numbers[right]>numbers[base]) {
			--right;
		}
		while (left < right && numbers[left] <= numbers[base]) {
			++left;
		}
		if (left == right) {
			break;
		}
		int temp = numbers[left];
		numbers[left] = numbers[right];
		numbers[right] = temp;
	}
	return left;
}
