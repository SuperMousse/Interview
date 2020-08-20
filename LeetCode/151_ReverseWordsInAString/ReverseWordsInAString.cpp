string reverseWords(string s) {
    if (s.empty()) {
        return s;
    }
    int ptr = 0;
    int len = s.size();
    // reverse overall string
    reverse(s.begin(), s.end());
    // reverse word one by one
    for (int i = 0; i < len; ++i) {
        if (s[i] != ' ') {
            if (ptr != 0) {
                s[ptr++] = ' '; // 如果扫描到非起始点, 插入一个' '
            }
            int j = i;
            // 拷贝从i开始到i之后的第一个非' '字符
            while (j < len && s[j] != ' ') {
                s[ptr++] = s[j++];
            }
            string::iterator beg = s.begin() + ptr - (j - i);
            string::iterator end = s.begin() + ptr;
            reverse(beg, end);
            i = j;
        }
    }
    return s.substr(0, ptr);
}
