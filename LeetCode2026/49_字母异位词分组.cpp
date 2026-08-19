// 字母异位词是通过重新排列不同单词或短语的字母而形成的单词或短语，并使用所有原字母一次。
// 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

// 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
// 把字符相同, 但顺序不同的数组聚合到一起

// 扫描法
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.empty()) {
            return result;
        }
        unordered_map<string, vector<string>> map;
        map.reserve(strs.size());
        for (int i = 0; i < strs.size(); i++) {
            // 遍历每个字符串
            vector<int> char_count(26, 0);
            for (int j = 0; j < strs[i].size(); j++) {
                char_count[strs[i][j] - 'a']++;
            }
            // 把出现次数大于0的字母和出现次数按顺序拼成key
            string key;
            for (int k = 0; k < 26; k++) {
                if (char_count[k] != 0) {
                    key.push_back('a'+ k);
                    key += to_string(char_count[k]);
                    key.push_back(',');
                }
            }
            map[key].push_back(strs[i]);
        }
        for (auto& pair : map) {
            result.push_back(std::move(pair.second));
        }
        return result;
    }
};

// 排序法
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.empty()) {
            return result;
        }
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            map[temp].push_back(strs[i]);
        }
        for (auto& pair : map) {
            result.push_back(std::move(pair.second));
        }
        return result;
    }
};
