// 位运算加法，非递归
int Add(int num1, int num2)
{
	int sum, carry;
	// num2 = 0表示carry=0, 即再无进位
	while (num2 != 0) {
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;
		num1 = sum;
		num2 = carry;
	}
	return num1;
}

// 位运算加法, 递归
int Add(int num1, int num2)
{
        if(num2 == 0)
                return num1;
 
        int sum = num1 ^ num2;
        int carry = (num1 & num2) << 1;
 
        return Add(sum, carry);
}


// 位运算减法

// [x-y]=[x-y]补=[x]补-[y]补=[x]补+[-y]补
// 从[y]补求[-y]补的法则是：对[y]补包括符号位“求反且最末位加1”,即可得到[-y]补
int negative(int n)
{
	return add(~n, 1);
}

int sub(int a, int b)
{
	return add(a, negative(b));
}


// 位运算乘法
int is_negative(int n)
{
	if (n >> 31)
		return 1; // 负数
	else
		return 0; // 正数
}

int positive(int n)
{
	if (n >> 31)
		return negative(n);
	else
		return n;
}

int multiply(int a, int b)
{
	bool be_negative = false;
	if (is_negative(a) ^ is_negative(b))
		be_negative = true;

	unsigned int x = positive(a);
	unsigned int y = positive(b);
	int n = 0;
	while (y | 0)
	{
		if (y & 1)
			n = add(n, x);
		x = x << 1;
		y = y >> 1;
	}
	return be_negative ? negative(n) : n;
}
