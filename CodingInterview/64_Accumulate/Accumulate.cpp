// 牛客网解法
int Sum_Solution(int n) {
	int ans = n;
	ans && (ans += Sum_Solution(n - 1)); // 逻辑与短路求值, ans=0时后面不会再进行计算
	return ans;
}


// 剑指offer解法一
class Temp
{
public:
	Temp()
	{
		++N;
		Sum += N;
	}

	static void Reset()
	{
		N = 0;
		Sum = 0;
	}

	static unsigned int GetSum()
	{
		return Sum;
	}

private:
	static unsigned int N;
	static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

class Solution
{
public:
	int res;
	int Sum_Solution(int n)
	{
		Temp::Reset();

		Temp* a = new Temp[n];
		delete[] a;
		a = NULL;

		return Temp::GetSum();
	}
};


// 剑指offer解法二




// 剑指offer解法三: 函数指针
typedef int (*func)(int);

// 递归的终止函数
int Teminator(int n){
	return 0;
}

//  递归函数, 选择函数进行递归
int Recursion(int n){
	static func pf[2] ={Teminator, Recursion};

	return n + pf[!!n](n - 1);
}


class Solution
{
public:
	int Sum_Solution(int n){
		return Recursion(n);
	}

};


// 剑指offer解法四: 模版类型
template <unsigned int n>
struct Sum{
	enum Value{
		N = Sum< n - 1 >::N + n
	};
};

template <>
struct Sum<1>{
	enum Value{
		N = 1
	};
};
