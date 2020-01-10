 // 归并排序
 ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // cut the list into two part
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        
        // sort each half
        ListNode* pNode1 = sortList(head);
        ListNode* pNode2 = sortList(slow);
        
        //merge l1 and l2
        return merge(pNode1, pNode2);
    }
    ListNode* merge(ListNode* pNode1, ListNode* pNode2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* pCurrent = dummyHead;
        while(pNode1 != nullptr && pNode2 != nullptr) {
            if(pNode1->val < pNode2->val) {
                pCurrent->next = pNode1;
                pNode1 = pNode1->next;
            }
            else {
                pCurrent->next = pNode2;
                pNode2 = pNode2->next;
            }
            pCurrent = pCurrent->next;
        }
        // give the remain part to the other ptr
        pCurrent->next = (pNode1 == nullptr) ? pNode2 : pNode1;
        return dummyHead->next;
    }
    
// 快速排序
ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        quickSort(head, nullptr);
        return head;
    }
    
    void quickSort(ListNode* begin, ListNode* end) {
        if(begin == end) {
            return;
        }
        ListNode* mid = partition(begin, nullptr);
        quickSort(begin, mid);
        quickSort(mid->next, end);
        return;
    }
    
    ListNode* partition(ListNode* begin, ListNode* end) {
        ListNode* base = begin;
        ListNode* slow = begin;
        ListNode* fast = begin->next;
        while(fast != end){
            if(fast->val < base->val) {
                slow = slow->next;
                swap(slow->val, fast->val);
            }
            fast = fast->next;
        }
        swap(base->val, slow->val);
        return slow;
    }
