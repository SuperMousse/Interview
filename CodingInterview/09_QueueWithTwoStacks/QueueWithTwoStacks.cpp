// realize queue with two stack
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty()) {
			while (!stack1.empty()) {
				int data = stack1.top();
				stack1.pop();
				stack2.push(data);
			}
		}
		if (stack2.empty()) {
			throw runtime_error("queue is empty");
		}

		int head = stack2.top();
		stack2.pop();
		return head;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
