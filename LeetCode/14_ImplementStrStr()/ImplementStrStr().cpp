string longestCommonPrefix(vector<string>& strs) {
	string result = "";
	if (strs.empty()) {
		return result;
	}
	int minLen = strs[0].size();
	for (auto s : strs) {
		minLen = ((minLen < s.size()) ? minLen : s.size());
	}

	int beg = 0;
	while (beg <= minLen) {
		unordered_map<char, int> hash;
		for (auto s : strs) {
			hash[s[beg]] = 1;
		}
		if (hash.size() > 1) {
			break;
		}
		result += strs[0][beg];
		++beg;
	}
	return result;
}
