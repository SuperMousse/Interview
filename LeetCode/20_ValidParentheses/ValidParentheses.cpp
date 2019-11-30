class Solution {
public:
	bool isValid(string s) {
		if (s.empty()) {
			return true;
		}
		stack<char> parenthesis;
		unordered_map<char, char> mapping = { {')', '('}, {']', '['}, {'}', '{'} };
		int length = s.size();

		for (int i = 0; i < length; ++i)
		{
			char c = s[i];
			// closing bracket
			if (mapping.count(c) != 0) {
				char topElement = parenthesis.empty() ? '#' : parenthesis.top();
				if (topElement == mapping[c]) {
					parenthesis.pop(); // top element match, pop
				}
				else {
					return false;
				}
			}
			else {
				parenthesis.push(c); // opening bracket
			}
		}

		return parenthesis.empty();
	}
};
