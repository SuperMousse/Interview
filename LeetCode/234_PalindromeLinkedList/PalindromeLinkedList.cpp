// 解法一: 使用辅助空间, 堆栈



// 解法二: 不使用辅助空间, 时间复杂度O(N), 空间复杂度O(1)
// 思路: 将后半截链表进行翻转, 然后再前后同时移动指针进行比较
	 bool isPalindrome(ListNode* head) {
		 if (head == nullptr || head->next == nullptr) {
			 return true;
		 }
		 ListNode* slow = head;
		 ListNode* fast = head->next;
		 // find middle node
		 while (fast->next != nullptr && fast->next->next!= nullptr) {
			 slow = slow->next;
			 fast = fast->next->next;
		 }
		 if (fast->next == nullptr) {
			 slow->next = reverseList(slow->next);
			 slow = slow->next;
		 }
		 else {
			 slow->next->next = reverseList(slow->next->next);
			 slow = slow->next->next;
		 }
		 while (slow != nullptr) {
			 if (head->val != slow->val)
				 return false;
			 head = head->next;
			 slow = slow->next;
		 }

		 return true;
	 }

	 ListNode* reverseList(ListNode* head) {
		 ListNode* prev = nullptr;
		 ListNode* next = nullptr;
		 while (head != nullptr) {
			 next = head->next;
			 head->next = prev;
			 prev = head;
			 head = next;
		 }
		 return prev;
	 }
