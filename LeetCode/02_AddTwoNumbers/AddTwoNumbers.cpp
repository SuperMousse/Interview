// 我的傻瓜解法, 两字符串转数字相加, 然后再转字符串, 然后再创建一个链表
// 显然不是最好的解法




// 逐位运算, 参照加法运算, 考虑进位等
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* pHead = new ListNode(0);
	ListNode* pCurrent = pHead;
	ListNode* pNode1 = l1;
	ListNode* pNode2 = l2;
	int carry = 0;
	while (pNode1 != nullptr || pNode2 != nullptr) {
		int val1 = (pNode1 != nullptr) ? pNode1->val : 0;
		int val2 = (pNode2 != nullptr) ? pNode2->val : 0;
		int sum = val1 + val2 + carry;
		carry = sum / 10;
		pCurrent->next = new ListNode(sum % 10);
		pCurrent = pCurrent->next;
		if (pNode1 != nullptr) {
			pNode1 = pNode1->next;
		}
		if (pNode2 != nullptr) {
			pNode2 = pNode2->next;
		}
	}
	if (carry > 0) {
		pCurrent->next = new ListNode(carry);
	}
	return pHead->next;
}
