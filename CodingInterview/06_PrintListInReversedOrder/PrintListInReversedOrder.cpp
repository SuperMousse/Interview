vector<int> printListFromTailToHead(ListNode* head) {
	deque<int> temp;
	if (head != nullptr) {
		ListNode* pNode = head;
		while (pNode->next != nullptr) {
			temp.push_front(pNode->val);
			pNode = pNode->next;
		}
		temp.push_front(pNode->val);
	}
	vector<int> result(temp.begin(), temp.end());
	return result;
}
