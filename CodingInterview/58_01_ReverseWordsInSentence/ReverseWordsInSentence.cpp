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
    string ReverseSentence(string str) {
        if (str.empty()) {
            return str;
        }

        int mark = 0;
        int length = str.size();
        str += ' ';
        for (int i = 0; i < length + 1; ++i)
        {
            if (str[i] == ' ') {
                Reverse(str, mark, i - 1);
                mark = i + 1;
            }
        }

        str = str.substr(0, length);

        // 翻转整个句子
        Reverse(str, 0, length - 1);

        return str;
    }


// 我自己的解法
// follow牛客网的解法， 使用了STL的reverse接口
// 关键在于添加句尾的' ', 才能让句子最后面的单词完成翻转
// Hello, world
// 如果不添加句尾的‘ ’， world无法正常翻转
string ReverseSentence(string str) {
	reverse(str.begin(), str.end());
	str = str + ' ';
	string::iterator mark = str.begin();
	for (string::iterator it = str.begin(); it != str.end(); ++it) {
		if (*it == ' ') {
			reverse(mark, it);
			mark = it + 1;
		}
	}
	str = str.substr(0, str.size() - 1);
	return str;
}
