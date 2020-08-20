// 计算逆波兰表达式, 有效的运算符包括 +, -, *, / ,每一次的操作对象可能是证书或者另外一个表达式
// 注意: 两个整数相除应该被向零截断, 给定的逆波兰表达式总是有效的, 也就是总会有一个结果并且不会除0

//Input: ["2", "1", "+", "3", "*"]
//Output: 9
//Explanation: ((2 + 1) * 3) = 9

//Input: ["4", "13", "5", "/", "+"]
//Output: 6
//Explanation: (4 + (13 / 5)) = 6


int evalRPN(vector<string>& tokens) {
    if (tokens.empty()) {
        return 0;
    }
    stack<int> st;
    for (string t : tokens) {
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();
            if (t == "+") {
                st.push(left + right);
            }
            else if (t == "-") {
                st.push(left - right);
            }
            else if (t == "*") {
                st.push(left * right);
            }
            else if (t == "/") {
                st.push(left / right);
            }
        }
        else {
            st.push(stoi(t));
        }
    }
    return st.top();
}
