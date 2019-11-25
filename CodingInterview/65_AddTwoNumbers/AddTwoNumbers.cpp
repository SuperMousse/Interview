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

// [x-y]补=[x]补-[y]补=[x]补+[-y]补
// 从[y]补求[-y]补的法则是：对[y]补包括符号位“求反且最末位加1”,即可得到[-y]补
int negative(int n)
{
	return add(~n, 1);
}

int sub(int a, int b)
{
	return add(a, negative(b));
}


