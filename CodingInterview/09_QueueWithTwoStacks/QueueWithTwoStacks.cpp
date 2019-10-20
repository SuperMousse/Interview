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


// realize stack with two queue
class Solution
{
public:
	void push(int node) {
		if (queue1.empty() && queue2.empty()) {
			queue1.push(node);
		}
		else if (!queue1.empty()) {
			queue1.push(node);
		}
		else if(!queue2.empty()) {
			queue2.push(node);
		}
	}

	int pop() {
		int head = 0;
		if (!queue1.empty() && queue2.empty()) {
			for (int i = 0; i < queue1.size()-1; ++i)
			{
				int data = queue1.front();
				queue1.pop();
				queue2.push(data);
			}
			int head = queue1.front();
			queue1.pop();
		}
		if (queue1.empty() && !queue2.empty()) {
			for (int i = 0; i < queue2.size() - 1; ++i)
			{
				int data = queue2.front();
				queue2.pop();
				queue1.push(data);
			}
			int head = queue2.front();
			queue2.pop();
		}
		return head;
	}

private:
	queue<int> queue1;
	queue<int> queue2;
};
