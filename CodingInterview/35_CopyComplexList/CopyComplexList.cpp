struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};

// 剑指offer 解法
// 1. 复制链表所有节点，并将新复制的节点连接到旧节点后
// 2. 为新复制的节点设置random ptr
// 3. 将两个链表进行拆分
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
// 与剑指offer解法思路相同，但是进行了精简
