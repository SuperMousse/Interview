void DeleteNode(ListNode** pListHead, ListNode *pToBeDeleted){
	if (pListHead == nullptr || pToBeDeleted == nullptr) {
		return;
	}
	//删除的不是头结点也不是尾结点
	if (pToBeDeleted->next != nullptr) {
		ListNode* pNext = pToBeDeleted->next;
		pToBeDeleted->val = pNext->val;
		pToBeDeleted->next = pNext->next;

		delete pNext;
		pNext = nullptr;
	}
	// 删除的是头结点
	else if (pToBeDeleted == *pListHead) {
		delete pToBeDeleted;
		pToBeDeleted == nullptr;
		*pListHead == nullptr;
	}
	// 删除的是尾结点
	else {
		ListNode* pNode = *pListHead;
		while (pNode->next != pToBeDeleted) {
			pNode = pNode->next;
		}
		pNode->next == nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}
