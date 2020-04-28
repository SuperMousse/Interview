/*
Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
把1改成9， 然后把9删掉
*/

void deleteNode(ListNode* node) {
	ListNode* pNext = node->next;
	node->val = pNext->val;
	node->next = pNext->next;
	delete pNext;
	return;
}
