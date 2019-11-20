// 第一反应的解法, 哈希表

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


// 剑指offer解法
