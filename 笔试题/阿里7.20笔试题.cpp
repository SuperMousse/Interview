// 题一
// 给定数字n, 判断是否存在n=x+y+z, 使得x, y, z两两最大的公约数是k
// k \in [1, 10^18]

// 给定数字n, 判断是否存在n=x+y+z, 使得x, y, z两两最大的公约数是k
// k \in [1, 10^18]
// k * a + k * b + k * c = n
// k * (a + b + c) = n => (a + b + c) = n / k
// 找到a + b + c = n / k, 并且a, b, c两两互质, 并且互不相等

// 注意, 有人说int过不了, 需要long

// 最大公约数 greatest common divisor
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0 || b == 0)
        return 0;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);

    return gcd(a, b-a);
}

bool check(int a, int b, int c) {
    if (a != b && a != c && b != c &&
        gcd(a, b) == 1 && gcd(a, c) == 1 && gcd(b, c) == 1) {
        return true;
    }
    return false;
}

vector<int> threeSum(vector<int>& nums, int k) {
    vector<int> result;
    if (nums.size() < 3) {
        return result;
    }
    int length = nums.size();
    for (int i = 0; i < length - 2; ++i)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
            int left = i + 1;
            int right = length - 1;
            int sum = k - nums[i];
            while (left < right) {
                if (nums[left] + nums[right] == sum) {
                    if (check(nums[i], nums[left], nums[right])) {
                        result.push_back(nums[i]);
                        result.push_back(nums[left]);
                        result.push_back(nums[right]);
                        break;
                    }
                    ++left;
                    --right;
                }
                else if (nums[left] + nums[right] < sum) {
                    ++left;
                }
                else {
                    --right;
                }
            }
        }
    }

    return result;
}


vector<int> splitNum(int n, int k) {
    if (n < 3 || k < 1 || (n / k < 3) || (n % k) != 0) {
        return vector<int>();
    }
    vector<int> result;
    vector<int> factors;
    int multiple = n / k;
    for (int i = 1; i <= multiple; ++i) {
        factors.push_back(i);
    }
    result = threeSum(factors, multiple);
    for (auto n : result) {
        cout << n << " ";
    }
    cout << endl;

}



// 题目二
// 给定一个正整数，计算相邻数之差的绝对值，最后计算得出一位数，为7则是幸运数。
// 例如： 219，  |2 - 1| = 1， |1 - 9| = 8，  1 和 8 组合成 18， 然后继续计算， | 1 - 8 | = 7，所以219是幸运数。
// 218，  |2 - 1| = 1， |1 - 8| = 7，  1 和 8 组合成 17， 然后继续计算， | 1 - 7 | = 6，所以219不是幸运数。
// 输入： T组数据，每行输入L 和 R   （1  <= L <= R <= 10^9）。
// 输出 ： 计算区间内的幸运数个数。

// 3
// 1 10
// 1 1000
// 1 100000
	
// 1
// 28
// 498

// 题目: 魔法指纹: https://www.cnblogs.com/BCOI/p/9123169.html
// https://www.nowcoder.com/discuss/455839?type=1&channel=-2&source_id=discuss_tag_discuss_hot
