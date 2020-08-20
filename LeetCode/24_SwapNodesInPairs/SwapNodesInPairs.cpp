ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* pPrev = dummyHead;
    ListNode* pCurr = head;
    ListNode* pNext = nullptr;
    while (pCurr != nullptr && pCurr->next != nullptr) {
        pNext = pCurr->next;
        pPrev->next = pNext;
        pCurr->next = pNext->next;
        pNext->next = pCurr;
        pPrev = pCurr;
        pCurr = pPrev->next;
    }
    return dummyHead->next;
}
