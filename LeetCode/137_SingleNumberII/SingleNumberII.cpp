int singleNumber(vector<int>& nums) {
    if (nums.empty()) {
        return -1;
    }
    int bitLen = sizeof(int) * 8;
    unsigned bitMask = 0;
    vector<int> count(bitLen, 0);
    for (int n : nums) {
        bitMask = 1;
        for (int i = 0; i < bitLen; ++i) {
            if ((bitMask & n) != 0) {
                count[i] += 1; // 31存数字最低位
            }
            bitMask = bitMask << 1;
        }
    }

    bitMask = 1;
    int result = 0;
    for (int i = 0; i < bitLen; ++i) {
        if (count[i] % 3 != 0) {
            result = result ^ (bitMask << i);
        }
    }
    return result;

}
