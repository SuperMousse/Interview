// 解法一: 暴力解法, 依次遍历每个数字是否为质数
// 判断一个数字是否是质数, 解法一: 依次对小于它的每个数求余
//                     解法二: 依次对于小于sqrt(n)的每个数求余, 因为若不是质数, 拆成两数之积, 必定一个小于, 一个大于sqrt(n)
//                     解法三: 质数一定是6x+1或6x+5, 因为6x, 6x+2, 6x+3, 6x+4都一定不是质数, 所以6x, 6x+2, 6x+3,
//                            6x+4直接就是非质数, 在对依次对小于sqrt(n)中的6x+1或6x+5(6x-1)求余即可


// 解法二: 将所有小于根号n的数字依次*2, *3, *4..., 乘到的数字就是非质数
//        剩下没乘到的就是质数
int countPrimes(int n) {
    if(n <= 1) {
        return 0;
    }
    vector<bool> dp(n, false);
    dp[0] = true;
    dp[1] = true;
    for (int i = 2; i < sqrt(n); ++i) {
        if (dp[i] == false) {
            for (int j = 2; i * j < n; ++j) {
                dp[i * j] = true;
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; ++i) {
        if(dp[i] == false) {
            ++count;
        }
    }
    return count;
}
