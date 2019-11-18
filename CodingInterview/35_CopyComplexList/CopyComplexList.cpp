// 剑指offer 解法
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};

RandomListNode* Clone(RandomListNode* pHead)
{
	CloneNodes(pHead);
	ConnectRandomNodes(pHead);
	return ReconnectNodes(pHead);
}

void CloneNodes(RandomListNode* pHead){
	RandomListNode* pNode = pHead;
	while (pNode != nullptr) {
		RandomListNode* pCloned = new RandomListNode(pNode->label);
		pCloned->next = pNode->next;
		pCloned->random = nullptr;
		
		pNode->next = pCloned;
		pNode = pCloned->next;
	}
}

void ConnectRandomNodes(RandomListNode* pHead) {
	RandomListNode* pNode = pHead;
	while (pNode != nullptr) {
		RandomListNode* pCloned = pNode->next;
		if (pNode->random != nullptr) {
			pCloned->random = pNode->random->next;
		}

		pNode = pCloned->next;
	}
}

RandomListNode* ReconnectNodes(RandomListNode* pHead) {
	RandomListNode* pNode = pHead;
	RandomListNode* pClonedHead = nullptr;
	RandomListNode* pClonedNode = nullptr;
	if (pNode != nullptr) {
		pClonedHead = pNode->next;
		pClonedNode = pNode->next;
		pNode->next = pClonedNode->next;
		pNode = pNode->next;
	}
	while (pNode != nullptr) {
		pClonedNode->next = pNode->next;
		pClonedNode = pClonedNode->next;

		pNode->next = pClonedNode->next;
		pNode = pNode->next;
	}
	return pClonedHead;
}




// 牛客网解法
