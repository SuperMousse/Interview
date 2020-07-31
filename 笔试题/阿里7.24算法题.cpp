// 题一
// 吃烧饼。有n个盘子，每个盘子内有w[i]个烧饼。每次选取一个1≤x≤n，可以在1~x盘子中每个盘子吃一个烧饼。若这x个盘子中有空盘时无法进行该操作
// 问经过任意多次这种操作后，最多可以吃掉多少烧饼。
// 分析：对每个盘子，最多可吃的数量为：它和它前面的盘子中最少的烧饼数。

// 输入：
// 3
// 2 1 3
// 输出：
// 4

// 对每个盘子，最多可吃的数量为：它和它前面的盘子中最少的烧饼数

int maxCake(vector<int> cake) {
    if (cake.empty()) {
        return 0;
    }
    int curCake = 0;
    int result = 0;
    for (auto c : cake) {
        curCake = min(curCake, c);
        result += curCake;
    }
    return result;
}


// 题二

// N行L列的灯，有L个开关，第i个可以控制第i列，使得该列灯状态反转（开变关，关变开）。行之间可以任意交换。
// 问给定初始灯状态s和目标灯状态t，能否从初始变到目标状态，能的话最少要按几次开关

// s的第1行s1一定对应t的某一行tk。如果已知k，通过对比s1和tk各列的灯状态可以得知每一个开关Li是否需要打开
// 由于行之间可以任意交换, 所以使得灯的行集合{s1, ..., sN}和{t1, ..., tN}相等即可
// 用二进制数表示每一行灯的开关状态，如0010表示第三列灯开, 其他灯关
// 时间复杂度：我们需要对k=1,...,N做搜索。每次搜索需要判断集合是否相等，这可以在O(NL)的时间内完成；总体复杂度O(N2L)


#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long
 
using namespace std;
 
ll T, n, l, a[151], b[151], ans;
bool in[151];
char c;
 
ll getnum(ll x) {//得到二进制
	if (!x) return 1;
	ll sum = getnum(x / 2);
	if (x % 2 == 0) return sum * sum;
	return sum * sum * 2;
}
 
ll getans(ll x) {//得到要按的个数
	ll sum = 0;
	while (x) {
		if (x % 2 == 1) sum++;
		x /= 2;
	}
	return sum;
}
 
int main() {
	scanf("%d", &T);//读入
	
	for (int t = 1; t <= T; t++) {
		memset(a, 0, sizeof(a));//初始化
		memset(b, 0, sizeof(b));
		ans = 2147483647;
		
		scanf("%lld %lld", &n, &l);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= l; j++) {
				c = getchar();
				while (c != '1' && c != '0') c = getchar();
				if (c == '1') a[i] += getnum(l - j);//用二进制存
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= l; j++) {
				c = getchar();
				while (c != '1' && c != '0') c = getchar();
				if (c == '1') b[i] += getnum(l - j);//这个也是用二进制存
			}
		
		for (int i = 1; i <= n; i++) {//找和谁匹配
			bool yes = 0;
			ll dif = a[1] ^ b[i];//异或
			memset(in, 0, sizeof(in));
			in[i] = 1;
			
			for (int j = 2; j <= n; j++) {
				yes = 1;
				for (int k = 1; k <= n; k++)
					if (!in[k] && (ll)(a[j] ^ b[k]) == dif) {//配对
						yes = 0;
						in[k] = 1;
						break;
					}
				if (yes) break;//没得配对
			}
			if (yes) continue;
			
			ans = min(ans, getans(dif));//求出最少要按多少次
		}
		
		if (ans == 2147483647) printf("Impossible\n");//一定按不出来
			else printf("%lld\n", ans);//输出
	}
	
	return 0;
}
