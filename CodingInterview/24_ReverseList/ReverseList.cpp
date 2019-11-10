struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};


// 非递归解法
ListNode* ReverseList(ListNode* pHead) {
	if (pHead == nullptr || pHead->next == nullptr) {
		return pHead;
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
ListNode* ReverseList(ListNode* pHead) {
	//如果链表为空或者链表中只有一个元素
	if (pHead == nullptr || pHead->next == nullptr) 
		return pHead;

	//先反转后面的链表，走到链表的末端结点
	ListNode * pReverseNode = ReverseList(pHead->next);

	//再将当前节点设置为后面节点的后续节点
	pHead->next->next = pHead;
	pHead->next = nullptr;

	return pReverseNode;

}
