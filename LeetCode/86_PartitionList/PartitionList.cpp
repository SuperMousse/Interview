// 快排链表partition, 并且保留原有的数字相对顺序
// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5

ListNode* partition(ListNode* head, int x) {
    ListNode* smallHead = new ListNode(0);
    ListNode* bigHead = new ListNode(0);
    ListNode* small = smallHead;
    ListNode* big = bigHead;
    while (head != nullptr) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        }
        else {
            big->next = head;
            big = big->next;
        }
        head = head->next;
    }
    small->next = bigHead->next;
    big->next = nullptr; // 切断最后一个big的next, 防止出现环
    return smallHead->next;
}
