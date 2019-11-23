string LeftRotateString(string str, int n) {
	if (str.empty() || str.size() < n) {
		return str;
	}
	int length = str.size();
	Reverse(str, 0, n - 1);
	Reverse(str, n, str.size() - 1);
	Reverse(str, 0, length - 1);
	return str;
}

void Reverse(string& str, int begin, int end) {
	if (str.empty() || begin >= end) {
		return;
	}
	while (begin < end) {
		char temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;
		--end;
		++begin;
	}
}
