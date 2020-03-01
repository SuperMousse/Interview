// 数组中只出现一次的数字
// 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
vector<int> singleNumbers(vector<int>& nums) {
    if (nums.empty()) {
        return vector<int>();
    }
    vector<int> result;
    int sumOfNums = 0;
    int lastIndex = 0;
    for (auto n : nums) {
        sumOfNums ^= n;
    }
    
    while((sumOfNums & 0x1) != 1 && sumOfNums < 8*sizeof(int)) {
        sumOfNums >> 1;
        ++lastIndex;
    }
    
    int result1 = 0;
    int result2 = 0;
    for (auto n : nums) {
        if (((n >> lastIndex) & 0x1) == 1) {
            result1 ^= n;
        }
        else {
            result2 ^= n;
        }
    }
    result.push_back(result1);
    result.push_back(result2);
    return result;
}


// 在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
int singleNumber(vector<int>& nums) {
    if (nums.empty()) {
        throw runtime_error("sth wrong");
    }
    int bits[32] = {0};
    for (int i = 0; i < 32; ++i) {
        int count = 0;
        for(auto n : nums) {
            if(((n >> i) & 0x1 == 1)) {
                ++count;
            }
        }
        bits[31 - i] = count;
    }
    int result = 0;
    for (int i = 0; i < 32; ++i) {
        result << 1; // 移除掉最开始的符号位
        if((bits[i] % 3) == 1) {
            result += 1;
        }
    }
    return result;
}
