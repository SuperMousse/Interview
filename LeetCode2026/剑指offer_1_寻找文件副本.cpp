/*
设备中存有 n 个文件，文件 id 记于数组 documents。若文件 id 相同，则定义为该文件存在副本。请返回任一存在副本的文件 id。
示例 1：
输入：documents = [2, 5, 3, 0, 5, 0]
输出：0 或 5
*/
class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        unordered_map<int, int> map;
        for(auto& d: documents) {
            if (map.find(d) != map.end()) {
                return d;
            }
            map[d] = 1;
        }
        return -1;
    }
};

class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        // 因为所有数字都在0~n-1范围内，因此可以把数字放到对应索引上，如果第二次遇到这个数字，即此时索引数字=循环遍历的数字
        // 循环复杂度最多O(N)，因为i只到N
        // 交换复杂度最多为N次，因为一次交换documents[i]就会到对应索引的位置上
        int i = 0;
        int len = documents.size();
        while(i < len) {
            if (documents[i] == i) {
                // 此时索引与数字一致，应该查找下一个索引对应的数字了
                i++;
                continue;
            }
            if (documents[documents[i]] == documents[i]) {
                return documents[i];
            }
            swap(documents[i], documents[documents[i]]);
        }
        return -1;
    }
};
