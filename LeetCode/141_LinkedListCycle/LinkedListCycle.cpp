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
bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        if (slow == fast) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

// 额外解法
// 使用哈希表记录节点是否访问过, 若访问过则存在环
