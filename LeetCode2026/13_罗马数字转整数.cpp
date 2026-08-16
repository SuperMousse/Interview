class Solution {
public:
    // 从左往右扫描, 左侧需要大于等于右侧，这样加上去；否则减去；
    int romanToInt(string s) {
        unordered_map<char, int> dict = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        if(s.size() == 0) {
            return 0;
        }
        // 扫描异常字符
        // for (int i = 0; i < s.size(); i++) {
        //     if (dict.find(s[i]) == dict.end()){
        //         return 0;
        //     }
        // }
        int result = 0;
        for (int i = 0; i < s.size()-1; i++) {
            if (dict[s[i]] >= dict[s[i+1]]){
                result += dict[s[i]];
            } else {
                result -= dict[s[i]];
            }
        }
        result += dict[s[s.size()-1]];
        return result;
    }
};
