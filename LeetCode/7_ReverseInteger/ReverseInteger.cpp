// 整数123变为321, -123变为-321

int reverse(int x) {
    int result = 0;
    int sign = x > 0 ? 1 : -1;
    x = fabs(x); // 必须fabs, 不能abs, 否则会报错
    while (x > 0) {
        int tail = x % 10;
        // 如果result * 10 + tail > INT_MAX, 上溢出
        if ((INT_MAX - tail) / 10 < result) {
            return 0;
        }
        result = result * 10 + tail;
        x /= 10;
    }

    return sign * result;
}
