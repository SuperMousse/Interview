// 递归

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) {
			return l2;
		}
		else if (l2 == nullptr) {
			return l1;
		}

		ListNode* pMergedHead = nullptr;
		if (l1->val <= l2->val) {
			pMergedHead = l1;
			pMergedHead->next = mergeTwoLists(l1->next, l2);
		}
		else {
			pMergedHead = l2;
			pMergedHead->next = mergeTwoLists(l1, l2->next);
		}
		return pMergedHead;
	}
  
  
  // 非递归
