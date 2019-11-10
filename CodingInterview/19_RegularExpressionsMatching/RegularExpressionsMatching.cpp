
/*
	解这题需要把题意仔细研究清楚，反正我试了好多次才明白的。
	首先，考虑特殊情况：
		 1>两个字符串都为空，返回true
		 2>当第一个字符串不空，而第二个字符串空了，返回false（因为这样，就无法
			匹配成功了,而如果第一个字符串空了，第二个字符串非空，还是可能匹配成
			功的，比如第二个字符串是“a*a*a*a*”,由于‘*’之前的元素可以出现0次，
			所以有可能匹配成功）
	之后就开始匹配第一个字符，这里有两种可能：匹配成功或匹配失败。但考虑到pattern
	下一个字符可能是‘*’， 这里我们分两种情况讨论：pattern下一个字符为‘*’或
	不为‘*’：
		  1>pattern下一个字符不为‘*’：这种情况比较简单，直接匹配当前字符。如果
			匹配成功，继续匹配下一个；如果匹配失败，直接返回false。注意这里的
			“匹配成功”，除了两个字符相同的情况外，还有一种情况，就是pattern的
			当前字符为‘.’,同时str的当前字符不为‘\0’。
		  2>pattern下一个字符为‘*’时，稍微复杂一些，因为‘*’可以代表0个或多个。
			这里把这些情况都考虑到：
			   a>当‘*’匹配0个字符时，str当前字符不变，pattern当前字符后移两位，
				跳过这个‘*’符号；
			   b>当‘*’匹配1个或多个时，str当前字符移向下一个，pattern当前字符
				不变。（这里匹配1个或多个可以看成一种情况，因为：当匹配一个时，
				由于str移到了下一个字符，而pattern字符不变，就回到了上边的情况a；
				当匹配多于一个字符时，相当于从str的下一个字符继续开始匹配）
	之后再写代码就很简单了。
*/


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
