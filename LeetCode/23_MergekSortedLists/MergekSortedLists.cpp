// 方法一： 不断地两两合并链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return  l2;
    }
    if (l2 == nullptr) {
        return l1;
    }
    ListNode* pHead = nullptr;
    if (l1->val < l2->val) {
        pHead = l1;
        pHead->next = mergeTwoLists(l1->next, l2);
    }
    else {
        pHead = l2;
        pHead->next = mergeTwoLists(l1, l2->next);
    }
    return pHead;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
        return nullptr;
    }
    while (lists.size() > 1) {
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}



// 方法二: 堆
