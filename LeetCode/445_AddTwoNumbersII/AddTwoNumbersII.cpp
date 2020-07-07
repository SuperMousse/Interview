    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pNode1 = l1;
        ListNode* pNode2 = l2;
        stack<ListNode*> stack1;
        stack<ListNode*> stack2;
        while(pNode1 != nullptr) {
            stack1.push(pNode1);
            pNode1 = pNode1->next;
        }
        while (pNode2 != nullptr) {
            stack2.push(pNode2);
            pNode2 = pNode2->next;
        }
        int carry = 0;
        ListNode* pCurrent = new ListNode(0);
        while (!stack1.empty() && !stack2.empty()) {
            int num1 = !stack1.empty() ? stack1.top()->val : 0;
            int num2 = !stack2.empty() ? stack2.top()->val : 0;
            stack1.pop();
            stack2.pop();
            carry = carry + num1 + num2;
            pCurrent->val = carry % 10;
            ListNode* pHead = new ListNode(carry / 10);
            pHead->next = pCurrent;
            carry = carry / 10;
            pCurrent = pHead;
        }
        return pCurrent->val == 0 ? nullptr : pCurrent;  // 这个位置需要注意pcurretn位置上有可能是没有进位的情况下产生的0, 也有可能是进位产生的一个真实数字1或2
    }
