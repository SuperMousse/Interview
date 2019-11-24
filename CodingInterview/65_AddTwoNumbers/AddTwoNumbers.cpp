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
