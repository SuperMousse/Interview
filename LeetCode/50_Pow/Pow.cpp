// 快速幂
// 额外考虑INT_MIN溢出问题

double myPow(double x, int n) {
    if(n == 0) {
        return 1;
    }
    if(n == INT_MIN) {
        return myPow(1 / x, -(n + 1)) / x;
    }
    if (n < 0) {
        return myPow(1 / x, fabs(n));
    }
    double temp = x;
    double result = 1.0;
    while(n) {
        if(n & 0x1) {
            result *= temp;
        }
        temp *= temp;
        n = n >> 1;
    }
    return result;
}
