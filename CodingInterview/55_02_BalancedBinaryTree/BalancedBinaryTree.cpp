
// 解法一: 递归, 节点重复计算较多,简单但不推荐
bool IsBalanced_Solution(TreeNode* pRoot) {
	if (pRoot == nullptr) {
		return true;
	}
	int nLeft = TreeDepth(pRoot->left);
	int nRight = TreeDepth(pRoot->right);
  // 判断是否平衡二叉树从上向下判断, 不是的时候可以直接返回
  // 但是要确定是否是平衡二叉树还需要继续向下递归
	if (abs(nLeft - nRight) > 1) {
		return true;
	}

	return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}



int TreeDepth(TreeNode* pRoot) {
	if (pRoot == nullptr) {
		return 0;
	}
	int nLeft = TreeDepth(pRoot->left);
	int nRight = TreeDepth(pRoot->right);
	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}


// 解法二:每个节点只遍历一次
