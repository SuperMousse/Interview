// 给定单链表 L: L0 -> L1 -> ... -> Ln-1 -> Ln
// 重排成为: L': L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2
// 例子: 1->2->3->4  => 1->4->2->3
//    : 1->2->3->4->5 => 1->5->2->4->3.
// 分析: a. 找到中间节点 b. 后半部分链表反向, 等价于reverseBetween c. 链表节点重排

void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return;
    }
    // find the middle of the list
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    //Reverse the half after middle  1->2->3->4->5->6 to 1->2->3->6->5->4
    // 同LeetCode 92: reverseBetween
    ListNode* pPrev = slow; // node before reversed list
    ListNode* pCurr = slow->next; // the first node of reversed list
    ListNode* pNext = pCurr->next; // the node to be reversed
    while (pCurr->next != nullptr) {
        pCurr->next = pNext->next;
        pNext->next = pPrev->next;
        pPrev->next = pNext;
        pNext = pCurr->next;
    }

    // Start reorder one by one  1->2->3->6->5->4 to 1->6->2->5->3->4
    ListNode* pNode1 = head;
    ListNode* pNode2 = pPrev->next;
    while (pNode1 != pPrev) {
        pPrev->next = pNode2->next;
        pNode2->next = pNode1->next;
        pNode1->next = pNode2;
        pNode1 = pNode2->next;
        pNode2 = pPrev->next;
    }
    return;
}
