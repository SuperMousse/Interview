
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0 || n == 1) {
			return n;
		}
		else {
			int pre = 0;
			int post = 1;
			int result = 0;
			for (int i = 0; i < n-1; ++i) {
				result = pre + post;
				// swap
				pre=post;
				post = result;
			}
			return result;
		}
	}
};


// 快速幂递归
long long binpow(long long a, long long b) {
	if (b == 0) return 1;
	long long res = binpow(a, b / 2);
	if (b % 2)
		return res * res * a;
	else
		return res * res;
}

// 13转化为1101
// 1的时候要乘在res上, 0的时候不乘只是计算a的幂次并翻倍
// 快速幂非递归
long long binpow(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1) 
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
