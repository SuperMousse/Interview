// 判断数组是否是二叉树的后序遍历序列
bool VerifySquenceOfBST(vector<int> sequence) {
	if (sequence.empty()) {
		return false;
	}
	int length = sequence.size() - 1;
	return BST(sequence, 0, length);
}

bool BST(vector<int> sequence, int begin, int end) {
	if (sequence.empty() || begin > end) {
		return false;
	}
	int root = sequence[end];

	// 在二叉搜索树中左子树节点的值小于根节点的值
	int i = begin;
	for (; i < end; ++i) {
		if (sequence[i] > root) {
			break; // i坐标为右子树第一个节点
		}
	}

	// 在二叉搜索树中右子树节点的值大于根节点的值
	int j = i;
	for (; j < end; ++j) {
		if (sequence[j] < root) {
			return false;
		}
	}

	// 判断左子树是不是二叉搜索树
	bool left = true;
	if (i > begin) {
		left = BST(sequence, begin, i - 1);
	}

	// 判断右子树是不是二叉搜索树
	bool right = true;
	if (i < end - 1) {
		right = BST(sequence, i, end - 1);
	}
	return(left && right);
}


// 判断数组是否是二叉树的前序遍历序列
