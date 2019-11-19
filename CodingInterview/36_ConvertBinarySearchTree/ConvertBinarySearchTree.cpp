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

	pCurrent->left = *pLastNodeInList;
	if (*pLastNodeInList != nullptr) {
		(*pLastNodeInList)->right = pCurrent;
	}

	*pLastNodeInList = pCurrent;

	if (pCurrent->right != nullptr) {
		ConvertNode(pCurrent->right, pLastNodeInList);
	}
}
