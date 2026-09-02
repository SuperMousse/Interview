class Solution {
public:
    // 每一次可能走1步，或者两步，f(x) = f(x-1)+f(x-2)，用x而不是数组记录节约存储
    int climbStairs(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int x = 0;
        int x_1 = 2; // x-1，实际的2
        int x_2 = 1; // x-2，实际的1
        for (int i = 3; i <= n; i++) {
            x = x_1 + x_2;
            x_2 = x_1;
            x_1 = x;
        }
        return x;
    }
};
