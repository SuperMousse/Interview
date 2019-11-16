bool IsPopOrder(vector<int> pushV,vector<int> popV) {
	if(pushV.empty() || popV.empty() || pushV.size()!=popV.size())
		return false;
	stack<int> stack;
	int j = 0;
	for(int i = 0;i < pushV.size(); ++i){
		stack.push(pushV[i]);
		// 如果栈不为空，且栈顶元素等于弹出序列
		while(!stack.empty() && stack.top()==popV[j]){
			stack.pop(); //出栈
			++j; // 弹出序列向后一位
		}
	}
	if(stack.empty())
		return true;
	return false;
}
