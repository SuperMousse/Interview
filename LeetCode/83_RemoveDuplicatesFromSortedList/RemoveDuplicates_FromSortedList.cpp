// 删除重复节点, 但是留下一个, 不同于剑指offer的全部删掉
ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* pCurr = head;
    while (pCurr != nullptr) {
        while (pCurr->next != nullptr && pCurr->next->val == pCurr->val) {
            ListNode* pToBeDel = pCurr->next;
            pCurr->next = pCurr->next->next;
            delete pToBeDel;
            pToBeDel = nullptr;
        }
        pCurr = pCurr->next;
    }
    return head;
}
