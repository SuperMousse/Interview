struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};


// 非递归解法
ListNode* ReverseList(ListNode* pHead) {
	if (pHead == nullptr) {
		return nullptr;
	}
	ListNode* pReverseHead = nullptr;
	ListNode* pCurrent = pHead;
	ListNode* pPre = nullptr;
	ListNode* pNext = nullptr;
	while (pCurrent != nullptr) {
		pNext = pCurrent->next;
		if (pNext == nullptr) {
			pReverseHead = pCurrent;
		}
		pCurrent->next = pPre;
		pPre = pCurrent;
		pCurrent = pNext;
	}
	return pReverseHead;
}


// 递归解法
