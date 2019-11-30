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
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) {
			return l2;
		}
		else if (l2 == nullptr) {
			return l1;
		}

		ListNode* pNode1 = l1;
		ListNode* pNode2 = l2;
		ListNode* pMergedHead = nullptr;
		if (pNode1->val < pNode2->val) {
			pMergedHead = pNode1;
			pNode1 = pNode1->next;
		}
		else {
			pMergedHead = pNode2;
			pNode2 = pNode2->next;
		}
		ListNode* pCurrent = pMergedHead;

		while (pNode1 != nullptr && pNode2 != nullptr) {
			if (pNode1->val < pNode2->val) {
				pCurrent->next = pNode1;
				pCurrent = pCurrent->next;
				pNode1 = pNode1->next;
			}
			else {
				pCurrent->next = pNode2;
				pCurrent = pCurrent->next;
				pNode2 = pNode2->next;
			}
		}

		if (pNode1 == nullptr && pNode2 != nullptr) {
			pCurrent->next = pNode2;
		}
		if (pNode1 != nullptr && pNode2 == nullptr) {
			pCurrent->next = pNode1;
		}

		return pMergedHead;
	}
