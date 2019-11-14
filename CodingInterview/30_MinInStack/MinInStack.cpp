// 
class Solution {
public:
	void push(int value) {
		data_stack.push(value);
		if (min_stack.empty() || value < min_stack.top()) {
			min_stack.push(value);
		}
		else {
			min_stack.push(data_stack.top());
		}
	}
	void pop() {
		min_stack.pop();
		data_stack.pop();
	}
	int top() {
		return data_stack.top();
	}
	int min_() {
		return min_stack.top();
	}
private:
	stack<int> data_stack;
	stack<int> min_stack;
};




class Solution {
public:
	void push(int value) {
		data_stack.push(value);
		if (min_stack.empty() || value < min_stack.top())
			min_stack.push(value);

	}
	void pop() {
		if (min_stack.top() == data_stack.top())
			min_stack.pop();
		data_stack.pop();
	}
	int top() {
		return data_stack.top();
	}
	int min() {
		return min_stack.top();
	}
private:
	stack<int> data_stack;
	stack<int> min_stack;
};
