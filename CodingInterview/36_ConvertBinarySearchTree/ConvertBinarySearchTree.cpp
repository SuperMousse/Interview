// 剑指offer解法
TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode* pLastNodeInList = nullptr;
	ConvertNode(pRootOfTree, &pLastNodeInList);

	// pLastNodeInList指向双向链表的尾节点
	// 我们需要返回头结点
	TreeNode* pHeadOfList = pLastNodeInList;
	while (pHeadOfList != nullptr && pHeadOfList->left != nullptr) {
		pHeadOfList = pHeadOfList->left;
	}

	return pHeadOfList;
}

void ConvertNode(TreeNode* pNode, TreeNode** pLastNodeInList) {
	if (pNode == nullptr) {
		return;
	}
	TreeNode* pCurrent = pNode;

	if (pCurrent->left != nullptr) {
		ConvertNode(pCurrent->left, pLastNodeInList);
	}

	// 连接当前节点与左子树的最小节点
	pCurrent->left = *pLastNodeInList;  // 处理当前节点到pLastNodeInlist的左链接
	if (*pLastNodeInList != nullptr) {
		(*pLastNodeInList)->right = pCurrent; // 处理pLastNodeInlist到当前节点右链接
	}

	// 切换pLastNodeInList到当前节点, 即中序遍历的根节点处理 
	*pLastNodeInList = pCurrent;

	if (pCurrent->right != nullptr) {
		ConvertNode(pCurrent->right, pLastNodeInList);
	}
}
