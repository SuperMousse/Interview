
int getDecimalValue(ListNode* head) {
    if (head == nullptr) {
        return 0;
    }
    int num = 0;
    ListNode* pNode = head;
    while (!pNode) {
        num <<= 1;
        num += pNode->val;
        pNode = pNode->next;
    }
    return num;
}
