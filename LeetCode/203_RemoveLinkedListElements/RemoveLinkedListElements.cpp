// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5

ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr) {
        return head;
    }
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* pNode = dummyHead;
    while (pNode != nullptr) {
        ListNode* pNext = pNode->next;
        if (pNext != nullptr && pNext->val == val) {
            pNode->next = pNext->next;
            delete pNext;
        }
        else {
            pNode = pNode->next;
        }
    }
    return dummyHead->next;
}
