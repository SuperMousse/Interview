class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int max_len = 0;
        int current_len = 0;
        unordered_map<char, int> position_map;
        for (int i = 0; i < s.size(); ++i) {
            // current_len是当前维持的窗口, 当字符没出现过, 或者上次出现位置已经不在当前滑窗范围内时, 可以++
            if (position_map.find(s[i]) == position_map.end() || (i - position_map[s[i]] > current_len)) {
                ++current_len;
            } else {
                current_len = i - position_map[s[i]];
            }
            position_map[s[i]] = i;
            if (current_len > max_len) {
                max_len = current_len;
            }
        } 
        return max_len;
    }
};
