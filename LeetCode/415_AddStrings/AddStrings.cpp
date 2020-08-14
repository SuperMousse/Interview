
string addStrings(string num1, string num2) {
    if (num1.empty()) {
        return num2;
    }
    if (num2.empty()) {
        return num1;
    }
    int ptr1 = num1.size() - 1;
    int ptr2 = num2.size() - 1;
    int sum = 0;
    int carry = 0;
    string res = "";
    while (ptr1 >= 0 || ptr2 >= 0) {
        int n1 = ptr1 >= 0 ? (num1[ptr1] - '0') : 0;
        int n2 = ptr2 >= 0 ? (num2[ptr2] - '0') : 0;
        sum = n1 + n2 + carry;
        res = (char)('0' + sum % 10) + res;
        carry = sum / 10;
        --ptr1;
        --ptr2;
    }
    if (carry > 0) {
        res = (char)('0' + carry) + res;
    }
    return res;
}
