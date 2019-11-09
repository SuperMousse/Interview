bool matchCore(char* str, char* pattern) {
	if (*str == '\0' && *pattern == '\0') {
		return true;
	}
	//if (*str == '\0' && *pattern != '\0') { // 这句加入会导致结果错误
	//	return false;
	//}
	if (*str != '\0' && *pattern == '\0') {
		return false;
	}

	if (*(pattern + 1) == '*') {
		if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
			//move on the next state                  //stay on the current state    // ignore a '*'     
			return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern+2);
		}
		else {
			return matchCore(str, pattern+2);
		}
	}
	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchCore(str+1, pattern+1);
	return false;

}

bool match(char* str, char* pattern) {
	if (str == nullptr || pattern == nullptr) {
		return false;
	}
	return matchCore(str, pattern);
}
