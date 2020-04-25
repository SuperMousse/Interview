// 方法1, 循环
// 方法2， 3^19是int范围内最大的3的幂，那么任何3的幂次都是3^19的因子

bool isPowerOfThree(int n) {
	if (n == 0) {
		return false;
	}
	while (n != 1) {
		if (n % 3 != 0) {
			return false;
		}
		n /= 3;
	}
	return true;
}
