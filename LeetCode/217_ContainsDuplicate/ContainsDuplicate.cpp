bool containsDuplicate(vector<int>& nums) {
	if (nums.empty()) {
		return false;
	}
	int length = nums.size();
	unordered_map<int, int> hash;
	for (auto n : nums) {
		cout << n << endl;
		if (hash.count(n) == 1) {
			return true;
		}
		else {
			hash[n] = 1;
		}
	}
	return false;
}
