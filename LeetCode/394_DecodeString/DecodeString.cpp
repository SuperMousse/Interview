// 测试样例, 2[a]3[b], 2[3[b]6[c]]
string decodeString(string s) {
    if (s.empty()) {
        return string();
    }
    stack<int> intStack;
    stack<string> strStack;
    string curStr;
    int curNum = 0;
    for(char c : s) {
        if (c == '[') {
            intStack.push(curNum);
            strStack.push(curStr);
            curStr = "";
            curNum = 0;
        }
        else if(c == ']') {
            string temp = curStr; // temp是括号内的str
            curStr = strStack.top(); // curStr是前一次的str
            strStack.pop();
            curNum = intStack.top();
            intStack.pop();
            for (; curNum > 0; --curNum) {
                curStr += temp;
            }
        }
        else if(isdigit(c)) {
            curNum = curNum * 10 + (c - '0');
        }
        else {
            curStr += c;
        }
    }
    cout << curStr;
    return curStr;

}
