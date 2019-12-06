// 剑指offer解法
 bool hasCycle(ListNode* head) {
		 if (head == nullptr) {
			 return false;
		 }
		 ListNode* slow = head->next;
		 if (slow == nullptr) {
			 return false;
		 }
		 ListNode* fast = slow->next;
		 while (slow != nullptr && fast != nullptr) {
			 if (slow == fast) {
				 return true;
			 }
			 slow = slow->next;
			 fast = fast->next;
			 if (fast != nullptr) {
				 fast = fast->next;
			 }
		 }
		 return false;
	 }
   
   
// 我的解法
bool hasCycle(ListNode* head) {
		 if (head == nullptr) {
			 return false;
		 }
		 ListNode* slow = head;
		 ListNode* fast = head;
		 if (fast->next != nullptr) {
			 fast = fast->next;
			 if (fast->next != nullptr) {
				 fast = fast->next;
			 }
			 else {
				 return false;
			 }
		 }
		 else {
			 return false;
		 }
		 while (slow != fast) {
			 slow = slow->next;
			 if (fast->next != nullptr) {
				 fast = fast->next;
				 if (fast->next != nullptr) {
					 fast = fast->next;
				 }
				 else {
					 return false;
				 }
			 }
			 else {
				 return false;
			 }
		 }
		 return true;
	 }


// 额外解法
// 使用哈希表记录节点是否访问过, 若访问过则存在环
