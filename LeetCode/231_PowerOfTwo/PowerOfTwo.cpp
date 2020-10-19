// 判断n是否是2的幂次, 如果是2的幂次表示二进制只有1位为1
bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }
    return !(n & (n - 1));
}
