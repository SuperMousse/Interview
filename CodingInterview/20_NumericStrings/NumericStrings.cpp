// 数字的格式可以用A[.[B]][e|EC]表示，其中A和C都是整数，
// (可以有正负号，也可以没有)，而B是一个无符号整数

bool scanUnsignedInteger(char** string) {
	// 指针的指针, 修改了string指向的值，函数外部也可以获得改变
	// 如果只是使用指针，传递的是指针的值拷贝
	const char* before = *string;
	while (**string != '\0' && **string >= '0' && **string <= '9') {
		++(*string);
	}
	//当string中存在若干0~9的数字时，返回true
	return *string > before;
}

bool scanInteger(char** string) {
	if (**string == '+' || **string == '-') {
		++(*string);
	}
	return scanUnsignedInteger(string);
}

bool isNumeric(char* string)
{
	if (string == nullptr) {
		return false;
	}
	bool numeric = scanInteger(&string);

	//如果出现'.'，则接下来是数字的小数部分
	if (*string == '.') {
		++string;

		// 下面一行代码用||的原因
		// 1.小数可以没有整数部分，如.123等于0.123
		// 2. 小数点后面可以没有数字，如233.等于233.0
		// 3. 当然小数点前和后面可以都有数字，如233.666
		numeric = scanUnsignedInteger(&string) || numeric;
	}
	if (*string == 'e' || *string == 'E') {
		++string;
		// 下面一行代码用&&的原因
		// 1. 当e或E前面没有数字时，整个字符串不能表示数字，如.e1、e1
		// 2. 当e或E后面没有整数时，整个字符串不能表示数字，如12e、12e+5.4
		numeric = numeric && scanInteger(&string);
	}
	return numeric && *string == '\0';
}
