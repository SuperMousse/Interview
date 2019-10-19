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

vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> temp;
	if (head != nullptr) {
		ListNode* pNode = head;
		while (pNode->next != nullptr) {
			temp.push_back(pNode->val);
			pNode = pNode->next;
		}
		temp.push_back(pNode->val);
	}
	vector<int> result(temp.rbegin(), temp.rend());
	return result;
}

vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> result;
	if (head != nullptr) {
		ListNode* pNode = head;
		while (pNode->next != nullptr) {
			result.insert(result.begin(), pNode->val);
			pNode = pNode->next;
		}
		result.insert(result.begin(), pNode->val);
	}
	return result;
}
