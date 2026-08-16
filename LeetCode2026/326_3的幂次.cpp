class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 0 || n == 0) {
            return false;
        }
        if (n == 1 || n == 3 || n == 9) {
            return true;
        }
        while (n >= 1) {
            if (n == 1) {
                break;
            }
            if (n % 3 != 0) {
                return false;
            }
            n = n / 3;
        }
        return true;
    }
};
