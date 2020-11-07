// 给定两个相同长度的字符串s1, s2, 如果s1能够break s2, 或者s2能够break s1, return true
// s1 break s2 (both of size n): if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.

// Input: s1 = "abc", s2 = "xya"
// Output: true
// Explanation: "ayx" is a permutation of s2="xya" which can break to string "abc"
//              which is a permutation of s1="abc".

// Input: s1 = "abe", s2 = "acd"
// Output: false
// Explanation: All permutations for s1="abe" are: "abe", "aeb", "bae", "bea", "eab"
//              and "eba" and all permutation for s2="acd" are: "acd", "adc", "cad",
//              "cda", "dac" and "dca". However, there is not any permutation from s1
//              which can break some permutation from s2 and vice-versa.

bool checkIfCanBreak(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    vector<int> bucket1(26, 0);
    vector<int> bucket2(26, 0);
    for (int i = 0; i < s1.size(); ++i) {
        ++bucket1[s1[i] - 'a'];
        ++bucket2[s2[i] - 'a'];
    }
    int count1 = 0;
    int count2 = 0;
    bool smallS1 = false;
    bool smallS2 = false;
    for (int i = 0; i < 26; ++i) {
        count1 += bucket1[i];
        count2 += bucket2[i];
        if (count1 > count2) {
            if (smallS2) {
                return false; // 当前字符之前, s2中出现了较小字符, 不符合break对于0 and n-1所有字符的限制
            }
            smallS1 = true; // 当前s1中的较小字符比较多, s1更小
        }
        else if (count1 < count2) {
            if (smallS1) {
                return false;
            }
            smallS2 = true;
        }
    }
    return true;
}
