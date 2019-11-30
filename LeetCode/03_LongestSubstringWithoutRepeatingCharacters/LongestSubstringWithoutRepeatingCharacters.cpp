int lengthOfLongestSubstring(string s) {
		if (s.empty()) {
			return 0;
		}
		int* position = new int[256];
		memset(position, -1, sizeof(position));
		int length = s.size();
		int maxLength = 0;
		int currentLength = 0;

		for (int i = 0; i < length; ++i) {
			if (position[s[i]] < 0 || (i - position[s[i]]) > currentLength) {
				++currentLength;
			}
			else {
				currentLength = i - position[s[i]];
			}
			position[s[i]] = i;

			if (currentLength > maxLength) {
				maxLength = currentLength;
			}
		}

		return maxLength;

	}
