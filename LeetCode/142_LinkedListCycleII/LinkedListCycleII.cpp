ListNode *detectCycle(ListNode *head) {
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    // make sure there is a cycle
    while(slow != fast && fast->next != nullptr &&
          fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next == nullptr || fast->next->next == nullptr){
        return nullptr;
    }

    // calcalate the length of cycle
    int lenOfCycle = 1;
    fast = fast->next;
    while(slow != fast) {
        fast = fast->next;
        ++lenOfCycle;
    }

    // find the entry of cycle
    slow = head;
    fast = head;
    while(lenOfCycle > 0) {
        fast = fast->next;
        --lenOfCycle;
    }
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// 也可以直接在相遇后, slow=head, fast不变, 两指针相遇即为入口
