// 非递归

class Solution {
 public:
	 ListNode* reverseList(ListNode* head) {
		 if (head == nullptr) {
			 return nullptr;
		 }
		 ListNode* pHead = nullptr;
		 ListNode* pCurrent = head;
		 ListNode* pFront = nullptr;
		 ListNode* pBehind = nullptr;
		 while (pCurrent != nullptr) {
			 pFront = pCurrent->next;
			 if (pFront == nullptr) {
				 pHead = pCurrent;
			 }
			 pCurrent->next = pBehind;

			 pBehind = pCurrent;
			 pCurrent = pFront;
		 }
	 
		 return pHead;
	 }
 };

// 递归
ListNode* reverseList(ListNode* head) {
		 if (head == nullptr || head->next == nullptr) {
			 return head;
		 }
		 ListNode* pReverseNode = reverseList(head->next);

		 head->next->next = head;
		 head->next = nullptr;

		 return pReverseNode;
	 }
