// 给定一个数组(可能有重复元素), 随机输出一个给定元素的索引, 可以假设给定元素一定在数组中
// 要求不允许使用额外的内存空间
// 分析: 顺序扫描数组, 蓄水池抽样

// 将前k个数取出来放入结果集中，然后从第k+1个数开始遍历。假设遍历到第i个数，以k/i的概率替换掉蓄水池中的某个元素
// 代码实现: 前k个元素都放入， 对于第i个元素， rand一个[0, i]随机数d, 如果d<k, 则用数据流的第i个元素替换池子中的d号元素
class Solution {
public:
    Solution(vector<int>& nums) {
        data = nums;
    }

    int pick(int target) {
        int length = data.size();
        int index = 0;
        int count = 0;
        for (int i = 0; i < length; ++i) {
            if (target != data[i]) {
                continue;
            }
            if (count == 0) {  // 第一个target
                index = i;
            }
            else { // 多个target, 蓄水池大小为1
                if (rand() % (count + 1) < 1) {
                    index = i;
                }
            }
            ++count;
        }
        return index;
    }
private:
    vector<int> data;
};
