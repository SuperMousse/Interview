// 计算所有数字的和sum, 在[0, sum)内随机选择一个数字(均匀分布)
// 然后在累积和数组中找到这个数字, 因为随机选择这个数字的概率为: 区间长度 / sum
class Solution {
public:
    Solution(vector<int>& w) {
        int len = w.size();
        for (int i = 0; i < len; ++i) {
            sum += w[i];
            w[i] += (i == 0) ? 0 : w[i - 1];
            prob.push_back(w[i]);
        }
    }

    int pickIndex() {
        int target = rand() % sum;
        int left = 0;
        int right = prob.size() - 1;
        while (left != right) {
            int middle = left + (right - left) / 2;
            if (prob[middle] <= target) {
                left = middle + 1;
            }
            else {
                right = middle;
            }
        }
        return left;
    }
private:
    vector<double> prob;
    int sum = 0;
};
