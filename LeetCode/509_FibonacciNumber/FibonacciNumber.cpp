    int fib(int N) {
        if (N < 0) {
            return -1;
        }
        if (N < 2) {
            return N;
        }
        int prev = 0;
        int last = 1;
        int num = 0;
        for (int i = 2; i <= N; ++i) {
            num = prev + last;
            prev = last;
            last = num;
        }
        return num;
    }
