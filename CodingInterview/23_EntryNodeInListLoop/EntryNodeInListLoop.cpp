

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};


ListNode* MeetingNode(ListNode* pHead) {
	if (pHead == nullptr) {
		return nullptr;
	}
	ListNode* pSlow = pHead->next;
	if (pSlow == nullptr) {
		return nullptr;
	}
	ListNode* pFast = pSlow->next;
	while (pSlow != nullptr && pFast != nullptr) {
		if (pSlow == pFast) {
			return pSlow;
		}

		pSlow = pSlow->next;
		pFast = pFast->next;
		if (pFast != nullptr) {
			pFast = pFast->next;
		}

	}
	return nullptr;

}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (pHead == nullptr) {
		return nullptr;
	}
	ListNode* pMeetingNode = MeetingNode(pHead);
	if (pMeetingNode == nullptr) {
		return nullptr;
	}

	// 得到环中节点的数目
	int nodesInLoop = 1;
	ListNode* pNode = pMeetingNode;
	while (pNode->next != pMeetingNode) {
		++nodesInLoop;
		pNode = pNode->next;
	}

	// 双指针移动
	ListNode* pAhead = pHead;
	ListNode* pBehind = pHead;
	for (unsigned int i = 0; i < nodesInLoop; ++i) {
		pAhead = pAhead->next;
	}
	while (pAhead != pBehind) {
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	return pAhead;
}
