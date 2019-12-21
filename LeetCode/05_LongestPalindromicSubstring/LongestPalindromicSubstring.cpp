// 解法一: 中心拓展法
// 时间复杂度O(N^2), 空间复杂度O(1)
string longestPalindrome(string s) {
	if (s.size() <= 1) {
		return s;
	}
	int minLeft = 0;
	int maxRight = s.size() - 1;
	int maxLength = 1; // at least one character
	for (int middle = 0; middle < s.size(); ) {
		int left = middle;
		int right = middle;
		while (right < maxRight && s[right + 1] == s[right]) {
			++right; // skip duplicate characters in the middle, because equal character is palindrome
		}
		middle = right + 1; // next loop can jump these duplicate character
		while (right < maxRight && left > 0 && s[right + 1] == s[left - 1]) {
			++right; // Expand the selection as long it is a palindrom
			--left;
		}
		int newLength = right - left + 1; // record best palndrome
		if (newLength > maxLength) {
			minLeft = left;
			maxLength = newLength;
		}
	}
	return s.substr(minLeft, maxLength);
}


// 解法二: 动态规划
// 时间复杂度O(N)
