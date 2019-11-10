struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

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
