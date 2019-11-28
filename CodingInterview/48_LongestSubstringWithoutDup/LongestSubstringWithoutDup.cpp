// 剑指offer修正版本

int longestSubstringWithoutDuplication(const string& str){
	if (str.empty()) {
		return 0;
	}
	int curLength = 0; // f(i - 1)
	int maxLength = 0;

	vector<int> position(26, -1);

	for (int i = 0; i < str.length(); ++i) {
		int prevIndex = position[str[i] - 'a'];
		// 当前字母没有出现过或者出现在f(i-1)之前, curLength->f(i-1)
		if (prevIndex < 0 || (i - prevIndex) > curLength) {
			++curLength;
		}
		else {
			// (i - prevIndex) <= curLength
			curLength = i - prevIndex;
		}

		position[str[i] - 'a'] = i;

		if (curLength > maxLength) {
			maxLength = curLength;
		}

	}

	return maxLength;
}
