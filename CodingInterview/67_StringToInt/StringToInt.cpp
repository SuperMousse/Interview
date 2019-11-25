// string to int 注意事项
// 1. 全局标志位
// 2. 正负号处理
// 3. 数字超过int的最大值和最小值该怎么处理
// 4. 字符串为空串

enum status { kValid = 0, kInvalid };
int g_nStatus = kValid;

int StrToInt(string str) {
	g_nStatus = kInvalid;
	long long num = 0;
	string::iterator iter = str.begin();

	if (iter != str.end()) {
		bool minus = false;
		if (*iter == '+') {
			++iter;
		}
		else if (*iter == '-') {
			++iter;
			minus = true;
		}
		if (iter != str.end()) {
			num = StrToIntCore(str, iter, minus);
		}
	}

	return (int)num;
}

long long StrToIntCore(string& str, string::iterator iter, bool minus) {
	long long num = 0;
	while (iter != str.end()) {
		if (*iter >= '0' && *iter <= '9') {
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*iter - '0');

			if ((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000)) {
				num = 0;
				break;
			}
			++iter;
		}
		else {
			num = 0;
			break;
		}
	}

	if (iter == str.end()) {
		g_nStatus = kValid;
	}
	return num;
}
