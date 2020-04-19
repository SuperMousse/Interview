方法一: 二分搜索
begin = 0, end = INT_MAX, 看middle是否是根


方法二: 牛顿法
f(root) = root^2 - x = 0
f'(root) = 2 * root
root_new = root_old - f(root_old) / f'(root_old) = root_old - ( root_old^2 - x ) / (2 * root_old) = (root_old + x / root_old) / 2



int mySqrt(int x) {
    long res = x;
    while (res * res > x) {
        res = (res + x / res) / 2;
    }
    return res;
}
