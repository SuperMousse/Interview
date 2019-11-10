struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

// 单指针遍历两次
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == nullptr || k <= 0) {
		return nullptr;
	}
	unsigned int count = 0;
	ListNode* pCurrent = pListHead;
	while (pCurrent != nullptr) {
		++count;
		pCurrent = pCurrent->next;
	}
	if (count < k) {
		return nullptr;
	}
	count = count - k;
	pCurrent = pListHead;
	while (count > 0) {
		--count;
		pCurrent = pCurrent->next;
	}
	return pCurrent;

}

// 双指针遍历一次
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == nullptr || k <= 0) {
		return nullptr;
	}

	ListNode* pAhead = pListHead;
	ListNode* pBehind = pListHead;
	for (unsigned int i = 0; i < k - 1; ++i) {
		if (pAhead->next != nullptr) {
			pAhead = pAhead->next;
		}
		else {
			return nullptr;
		}
	}
	while (pAhead->next != nullptr) {
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	return pBehind;
}
