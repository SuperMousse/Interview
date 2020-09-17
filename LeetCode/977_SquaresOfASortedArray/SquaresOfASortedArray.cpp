vector<int> sortedSquares(vector<int>& A) {
    int len = A.size();
    vector<int> result(len, 0);
    int positive = 0;
    int negative = 0;
    while (positive < len && A[positive] < 0) {
        ++positive;
    }
    negative = positive - 1;

    int ptr = 0;
    while (positive < len && negative >= 0) {
        if (A[positive] * A[positive] < A[negative] * A[negative]) {
            result[ptr++] = A[positive] * A[positive];
            ++positive;
        }
        else {
            result[ptr++] = A[negative] * A[negative];
            --negative;
        }
    }
    while (positive < len) {
        result[ptr++] = A[positive] * A[positive];
        ++positive;
    }
    while (negative >= 0) {
        result[ptr++] = A[negative] * A[negative];
        --negative;
    }
    return result;
}
