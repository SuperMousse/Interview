 ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		 if (headA == nullptr || headB == nullptr) {
			 return nullptr;
		 }
		 ListNode* pNodeA = headA;
		 ListNode* pNodeB = headB;
		 int lengthA = 0;
		 int lengthB = 0;
		 while (pNodeA != nullptr) {
			 ++lengthA;
			 pNodeA = pNodeA->next;
		 }
		 while (pNodeB != nullptr) {
			 ++lengthB;
			 pNodeB = pNodeB->next;
		 }
		 int diff = lengthA - lengthB;
		 pNodeA = headA;
		 pNodeB = headB;
		 if (diff > 0) {
			 while (diff > 0) {
				 --diff;
				 pNodeA = pNodeA->next;
			 }
		 }
		 else {
			 while (diff < 0) {
				 ++diff;
				 pNodeB = pNodeB->next;
			 }
		 }

		 while (pNodeA != pNodeB) {
			 if (pNodeA == nullptr || pNodeB == nullptr) {
				 return nullptr;
			 }
			 pNodeA = pNodeA->next;
			 pNodeB = pNodeB->next;
		 }
		 return pNodeA;
		 
	 }
