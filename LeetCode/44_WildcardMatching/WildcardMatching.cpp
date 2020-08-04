// LeetCode 解法一
// 通配符匹配
// '?'表示单个任意字符， '*'表示多个任意字符

bool isMatch(string s, string p) {
    int pString = 0;
    int pPattern = 0;
    int match = 0;
    int start = -1;
    while (pString < s.size()) {
        //advancing both pointers when (both characters match) or ('?' found in pattern)
        //note that *p will not advance beyond its length
        if (pString < p.size() && (p[pPattern] == '?' || s[pString] == p[pPattern])) {
            ++pString;
            ++pPattern;
        }
        // * found in pattern, track index of *, only advancing pattern pointer
        else if (pPattern < p.length() && p[pPattern] == '*') {
            start = pPattern;
            match = pString;
            ++pPattern;
        }
        //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
        //only advancing pattern pointer
        else if (start != -1) {
            pPattern = start + 1;
            ++match;
            pString = match;
        }
        //current pattern pointer is not star, last patter pointer was not *
        //characters do not match
        else {
            return false;
        }
    }
    //check for remaining characters in pattern
    while (pPattern < p.size() && p[pPattern] == '*') {
        ++pPattern;
    }
    return pPattern == p.size();
}




// 解法二： KMP
