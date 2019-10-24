ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == nullptr) {
		return pHead;
	}
	ListNode* pPre = nullptr;
	ListNode* pCurrent = pHead;

	while (pCurrent != nullptr) {
		ListNode* pNext = pCurrent->next;
		bool needDelete = false;
		if (pNext != nullptr && pNext->val == pCurrent->val) {
			needDelete = true;
		}
		if (!needDelete) {
			pPre = pCurrent;
			pCurrent = pNext;
		}
		else {
			int value = pCurrent->val;
			ListNode* pToBeDel = pCurrent;
			while (pToBeDel != nullptr && pToBeDel->val == value) {
				pNext = pToBeDel->next;

				delete pToBeDel;
				pToBeDel = nullptr;
				pToBeDel = pNext;
			}
			if (pPre == nullptr) {
				pHead = pNext; // 第一个就是重复元素
			}
			else {
				pPre->next = pNext;
			}
			pCurrent = pNext;
		}
	}
	return pHead;
}
