class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) {
            return false;
        }
        stack<char> stack;
        unordered_map<char, char> map = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        for (int i = 0; i < s.size(); i++) {
            char temp = s[i];
            // 检测到右括号，此时需要看栈顶是否相等
            if (map.find(temp) != map.end()) {
                if (stack.empty() || map[s[i]] != stack.top()) {
                    return false;
                } else {
                    // 找到栈顶匹配的括号了，要出栈
                    stack.pop();
                }
            } else {
                // 左括号直接入栈
                stack.push(temp);
            }
        }
        return stack.empty();
    }
};
