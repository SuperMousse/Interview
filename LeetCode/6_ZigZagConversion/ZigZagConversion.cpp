// 字符串"PAYPALISHIRING"被zigzag写成如下所示:
// 分析： 蛇形写入, 奇数列一直自上向下, 偶数列一直自下向上, 并且没有第一行&最后一行
// P   A   H   N
// A P L S I I G
// Y   I   R
// 然后按行读出"PAHNAPLSIIGYIR"
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I

string convert(string s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    int length = s.size();
    int i = 0;
    vector<string> rows(numRows, "");
    while (i < length) {
        for (int j = 0; j < numRows && i < length; ++j) {
            rows[j].push_back(s[i++]);
        }
        for (int j = numRows - 2; j >= 1 && i < length; --j) {
            rows[j].push_back(s[i++]);
        }
    }
    string result = "";
    for (string r : rows) {
        result += r;
    }
    return result;
}

