TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == nullptr) {
			return nullptr;
		}
		TreeLinkNode* pNext = nullptr;
		if (pNode->right != nullptr) {
			TreeLinkNode* pRight = pNode->right;
			while (pRight->left != nullptr) {
				pRight = pRight->left;
			}
			pNext = pRight;
		}
		else if(pNode->right==nullptr){
			TreeLinkNode* pCurrent = pNode;
			TreeLinkNode* pParent = pNode->next;
			while (pParent != nullptr && pCurrent == pParent->right) {
				pCurrent = pParent;
				pParent = pParent->next;
			}
			pNext = pParent;
		}
		return pNext;
	}
