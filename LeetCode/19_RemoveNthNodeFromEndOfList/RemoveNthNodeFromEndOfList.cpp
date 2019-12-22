	 ListNode* removeNthFromEnd(ListNode* head, int n) {
		 if (head == nullptr || n < 1) {
			 return head;
		 }
		 ListNode* start = new ListNode(0);
		 start->next = head;
		 ListNode* slow = start;
		 ListNode* fast = start;

		 for (int i = 0; i <= n; ++i)
		 {
		     fast = fast->next;
		 }
		 while (fast != nullptr) {
			 slow = slow->next;
			 fast = fast->next;
		 }
		 ListNode* toBeDel = slow->next;
		 slow->next = slow->next->next;
		 delete toBeDel;
		 return start->next;
	 }
