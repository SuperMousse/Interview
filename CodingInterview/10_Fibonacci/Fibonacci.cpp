
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
