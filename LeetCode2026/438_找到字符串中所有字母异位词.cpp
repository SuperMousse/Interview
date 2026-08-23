class Solution {
public:
    // 时间复杂度: O(m+(n-m)*26), m为p的长度, n 为s的长度
    // 空间复杂度: 2*O(26)
    bool array_equal(vector<int>& array1, vector<int>& array2) {
        if (array1.size() == array2.size()) {
            for (int i = 0; i < array1.size(); i++) {
                if (array1[i] != array2[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) {
            return result;
        }
        vector<int> s_array(26, 0);
        vector<int> p_arrary(26, 0);
        // 先把最前面p个字符处理了, O(m)
        for(int i = 0; i < p.size(); i++) {
            s_array[s[i] - 'a'] += 1;
            p_arrary[p[i] - 'a'] += 1;
        }
        if (array_equal(s_array, p_arrary)) {
            result.push_back(0);
        }
        // 遍历字符串s, O((n-m)*26)
        for(int i = 0; i < (s.size() - p.size()); i++) {
            // s[0]推出, s[0+p.size()]推入
            s_array[s[i] - 'a'] -= 1;
            s_array[s[i + p.size()] - 'a'] += 1;
            if (array_equal(s_array, p_arrary)) {
                result.push_back(i+1);
            }
        }
        return result;
    }
};
