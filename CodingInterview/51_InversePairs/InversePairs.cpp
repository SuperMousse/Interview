// 解法一: 使用栈存储指针, 从队尾开始比较
// 时间复杂度O(m+n), 空间复杂度O(m+n)




// 解法二: 两次遍历测量两个链表的长度, 然后长链表先走diff步
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr || pHead2 == nullptr) {
			return nullptr;
		}
		unsigned int nLength1 = GetListLength(pHead1);
		unsigned int nLength2 = GetListLength(pHead2);

		// init
		int nLengthDiff = 0;
		ListNode* pListHeadLong = nullptr;
		ListNode* pListHeadShort = nullptr;
		if (nLength1 < nLength2) {
			pListHeadShort = pHead1;
			pListHeadLong = pHead2;
			nLengthDiff = nLength2 - nLength1;
		}
		else {
			pListHeadShort = pHead2;
			pListHeadLong = pHead1;
			nLengthDiff = nLength1 - nLength2;
		}

		// 先在长链表上走几步, 再同时在两个链表上遍历
		for (int i = 0; i < nLengthDiff; ++i){
			pListHeadLong = pListHeadLong->next;
		}

		while (pListHeadLong != nullptr && pListHeadShort != nullptr && (pListHeadLong != pListHeadShort)) {
			pListHeadLong = pListHeadLong->next;
			pListHeadShort = pListHeadShort->next;
		}

		// 得到第一个公共节点
		ListNode* pFirstCommonNode = pListHeadLong;

		return pFirstCommonNode;

	}

	unsigned int GetListLength(ListNode* pHead) {
		unsigned int nLength = 0;
		ListNode* pNode = pHead;
		while (pNode != nullptr) {
			++nLength;
			pNode = pNode->next;
		}
		return nLength;
	}
};
