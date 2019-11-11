struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

// 递归解法
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr) {
		return pHead2;
	}
	else if (pHead2 == nullptr) {
		return pHead1;
	}
	ListNode* pMergedHead = nullptr;
	if (pHead1->val < pHead2->val) {
		pMergedHead = pHead1;
		pMergedHead->next = Merge(pHead1->next, pHead2);
	}
	else {
		pMergedHead = pHead2;
		pMergedHead->next = Merge(pHead1, pHead2->next);
	}
	return pMergedHead;
}


// 非递归解法
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr) {
		return pHead2;
	}
	else if (pHead2 == nullptr) {
		return pHead1;
	}

	ListNode* pMergedHead = nullptr;
	ListNode* pCurrent = nullptr;
	while (pHead1 != nullptr && pHead2 !=nullptr)
	{
		if (pHead1->val<pHead2->val)
		{
			if (pMergedHead == nullptr) {
				pMergedHead = pHead1;
				pCurrent = pHead1;
			}
			else {
				pCurrent->next = pHead1;
				pCurrent = pCurrent->next;
			}
			pHead1 = pHead1->next;
		}
		else {
			if (pMergedHead == nullptr) {
				pMergedHead = pHead2;
				pCurrent = pHead2;
			}
			else {
				pCurrent->next = pHead2;
				pCurrent = pCurrent->next;
			}
			pHead2 = pHead2->next;
		}
	}

	if (pHead1 == nullptr) {
		pCurrent->next = pHead2;
	}
	else {
		pCurrent->next = pHead1;
	}
	return pMergedHead;
}
