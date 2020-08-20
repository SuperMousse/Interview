// 大数乘法, 从右向左逐位进行乘法, 然后加起来
// num1[i] * num2[j]将会被放在索引 [i + j, i + j + 1],
// 如3, 5的索引分别是 2, 1, 相乘之后的索引位置为3, 4
//       ---------
//           1 2 3
//           * 4 5
//       ---------
//             1 5
//           1 0
//         0 5
//       ---------
//           1 2
//         0 8
//       0 4
//       ---------
// idx: [0 1 2 3 4]

string multiply(string num1, string num2) {
    if (num1.size() < num2.size()) {
        swap(num1, num2);
    }
    int m = num1.size();
    int n = num2.size();
    int totalLen = m + n;
    vector<int> position(totalLen, 0);
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int multiply = (num1[i] - '0') * (num2[j] - '0');
            int pos1 = i + j;
            int pos2 = i + j + 1;

            int sum = multiply + position[pos2]; // total sum
            position[pos1] += sum / 10; // carry
            position[pos2] = (sum % 10); // res
        }
    }
    string res = "";
    for (int i = 0; i < totalLen; ++i) {
        // filter start with 0
        if (position[i] != 0 || res.size() != 0) {
            res.push_back(position[i] + '0');
        }
    }
    return res.size() == 0 ? "0" : res;
}
