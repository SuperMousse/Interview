1. 现有n个人, 要从这n个人中选任意数量的人组成一支队伍, 再在这些人中选出一名队长, 求不同的方案数对10^9 + 7取模的结果, 如果两个方案选取的人
的集合不同或选出的队长不同, 则认为这两个方案是不同的  
输入: 一行一个数字n, 1 <= n <= 10^9, 如2
输出: 一行一个数字表示答案, 如4

result = 0 * C_{N}^{0} + 1 * C_{N}^{1} + 2 * C_{N}^{2} + ... + N * C_{N}^{N}  
result = N * C_{N}^{N} + (N-1) * C_{N}^{N-1}           + ... + 0 * C_{N}^{0}  
2 * result = N * (C_{N}^{0} + C_{N}^{1} + ... + C_{N}^{N})  
    result = N * 2^{N-1}  


long long fastPow(long long base, long long N) {
    if(N == 0) {
        return 1;
    }
    if(N == 1) {
        return 2;
    }
    long long  result = 1.0;
    long long temp = base;
    
    while(N > 0) {
        if(N & 0x1 != 0) {
            result = (result % 1000000007) * (temp % 1000000007);
        }
        temp = (temp % 1000000007) * (temp % 1000000007);
        N >>= 1;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...



    long long N;
    cin >> N;
    cout << (N * fastPow(2, N - 1)) % 1000000007;

    
    return 0;
}

2. 小强在玩一个走迷宫的游戏, 他操纵的人物现在位于迷宫的起点, 他的目标是尽快的到达终点, 每一次他可以选择花费一个时间单位向上, 下, 左,右
走一格
