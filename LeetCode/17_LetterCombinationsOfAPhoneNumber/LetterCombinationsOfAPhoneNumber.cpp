// 暴力解法， 时间复杂度O(3^N)
	 vector<string> letterCombinations(string digits) {
		 vector<string> result;
		 if (digits.empty()) {
			 return result;
		 }
		 result.push_back(""); // 如果初始没有元素, 那么for k < result.size()会失效
		 string mapping[10] = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		 for (int i = 0; i < digits.size(); ++i)
		 {
			 vector<string> temp;
			 string character = mapping[digits[i] - '0'];
			 for (int j = 0; j < character.size(); ++j)
			 {
				 for (int k = 0; k < result.size(); ++k)
				 {
					 temp.push_back(result[k] + character[j]);
				 }
			 }
			 // result.swap(temp); // 这两句作用相同
			 result = temp;
		 }

		 return result;
	 }
