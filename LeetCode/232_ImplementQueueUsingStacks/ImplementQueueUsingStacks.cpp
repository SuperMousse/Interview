class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
        return;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                int data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
        int head = stack2.top();
        stack2.pop();
        return head;
    }

    /** Get the front element. */
    int peek() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                int data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
        return stack2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return (stack1.empty()) && (stack2.empty());
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
