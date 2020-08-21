// 假设数字为12321, 希望将数字的尾部数字反向为12312
//          x: 12321 -> 1232 -> 123 ->  12
// reverseNum:     0 ->    1 ->  12 -> 123

//          x:  1221 ->  122 ->  12
// reverseNum:     0 ->    1 ->  12

bool isPalindrome(int x) {
    // x<0或者最后一个数字为0时, 都不可能是回文数
    if (x < 0 || (x != 0 && x % 10 == 0)) {
        return false;
    }
    int reverseNum = 0;
    while (x > reverseNum) {
        reverseNum= reverseNum * 10 + x % 10;
        x /= 10;
    }
    // 位数为奇数的时候 x == reverseNum/10, 位数为偶数的时候 x == reverseNum
    return (x == reverseNum || (x == reverseNum / 10));
}
