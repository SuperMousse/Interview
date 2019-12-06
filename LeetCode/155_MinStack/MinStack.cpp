 class MinStack {
 public:
	 /** initialize your data structure here. */
	 MinStack() {

	 }

	 void push(int x) {
		 if (minStack.empty() || x < minStack.top()) {
			 minStack.push(x);
		 }
		 else {
			 minStack.push(minStack.top());
		 }

		 dataStack.push(x);
	 }

	 void pop() {
		 if (!dataStack.empty() && !minStack.empty() && dataStack.size() == minStack.size()) {
			 dataStack.pop();
			 minStack.pop();
		 }
		 else {
			 throw runtime_error("Something wrong when poping");
		 }
	 }

	 int top() {
		 if (!dataStack.empty()) {
			 return dataStack.top();
		 }
		 else {
			 throw runtime_error("Not enough element");
		 }
	 }

	 int getMin() {
		 if (!minStack.empty()) {
			 return minStack.top();
		 }
		 else {
			 throw runtime_error("Not enough element");
		 }
	 }
 private:
	 stack<int> dataStack;
	 stack<int> minStack;
 };
