// 1 -> 2 -> 3 -> 4 -> 5, m = 2, n = 4
// 加上dummyHead后变成 0 -> 1 -> 2 -> 3 -> 4 -> 5
// 找到pPrev = 1, pCurr = 2, pNext = 3
// first reversing, 交换 2, 3
// 0 -> 1 -> 3 -> 2 -> 4 -> 5; pPrev = 1, pCurr = 2, pNext = 4
// second reversing, 交换 3, 4
// 0 -> 1 -> 4 -> 3 -> 2 -> 5; pPrev = 1, pCurr = 2, pNext = 5 (finish)
// 分析: 每次先把current放到next的后面, 然后把next提到prev的后面, 最后把next放在current的后面, 因为current是此次交换的最后一个节点

ListNode* reverseBetween(ListNode* head, int m, int n) {
    // create a dummy node to mark the head of this list
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* pPrev = dummyHead; // node before the first reversed node
    ListNode* pCurr = nullptr;
    ListNode* pNext = nullptr;

    // find m-th node
    for (int i = 0; i < m - 1; ++i) {
        pPrev = pPrev->next;
    }
    pCurr = pPrev->next; // the first node of the reversed list
    pNext = pCurr->next; // node will be reversed

    for (int i = 0; i < n - m; ++i) {
        pCurr->next = pNext->next;
        pNext->next = pPrev->next;
        pPrev->next = pNext;
        pNext = pCurr->next;
    }

    return dummyHead->next;
}
