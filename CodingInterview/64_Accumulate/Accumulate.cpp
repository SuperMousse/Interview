// 牛客网解法
int Sum_Solution(int n) {
	int ans = n;
	ans && (ans += Sum_Solution(n - 1)); // 逻辑与短路求值, ans=0时后面不会再进行计算
	return ans;
}


// 剑指offer解法一
