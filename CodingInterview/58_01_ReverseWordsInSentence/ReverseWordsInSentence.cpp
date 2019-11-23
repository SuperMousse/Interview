// 剑指offer解法
string ReverseSentence(string str) {
	if (str.empty()) {
		return str;
	}
	int begin = 0;
	int end = str.size() - 1;
	// 翻转整个句子
	Reverse(str, begin, end);

	// 翻转句子中的每个单词
	begin = end = 0;
	while (begin < str.size()) {
		if (str[begin] == ' ') {
			++begin;
			++end;
		}
		else if (str[end] == ' ' || end == str.size()) {
			Reverse(str, begin, --end);
			begin = ++end;
		}
		else {
			++end;
		}
	}
	return str;
	
}


void Reverse(string& str, int begin, int end) {
	if (begin > end) {
		return;
	}
	while (begin < end) {
		char temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;
		++begin;
		--end;
	}
}

// 牛客网解法
