ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k < 0) {
            return head;
        }
        // 制作环
        int listLen = 1;
        ListNode* pNode = head;
        while(pNode->next != nullptr) {
            ++listLen;
            pNode = pNode->next;
        }
        if(k % listLen == 0) {
            return head;
        }

        pNode->next = head;
        int shiftLen = listLen - k % listLen; 
        pNode = head;
        ListNode* pPrev = nullptr;
        while(shiftLen > 0) {
            pPrev = pNode;
            pNode = pNode->next;
            --shiftLen;
        }
        pPrev->next = nullptr;
        
        return pNode;
        
    }
